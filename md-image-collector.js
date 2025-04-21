// md-image-collector.js
/*
运行：node md-image-collector.js


描述：
1. 文件内容比较功能：

添加了areFilesIdentical函数，使用MD5哈希比较两个文件的内容
只有当文件内容不同时才会重命名文件，避免不必要的重命名


2. 针对本地图片的处理：

当目标文件夹中已有同名文件时:

先比较内容是否相同
如果内容相同，直接使用现有文件，不进行复制
只有在内容不同时才添加时间戳并复制文件




3. 针对网络图片的处理：

将网络图片下载到临时文件
与已存在的同名文件比较内容
如果内容相同，删除临时文件并使用现有文件
只有在内容不同时才重命名保留


4.增加日志信息：

在跳过复制相同文件时添加提示信息
便于了解脚本的处理过程


5. 使用方法
使用方式与之前相同，但现在在配置中可以控制是否处理网络图片：
javascript// 配置信息
const config = {
    // Markdown文件所在目录
    mdDir: "F:/code/code/Markdown",
    // 图片收集的目标文件夹的根目录
    imageRootDir: 'F:/code/code/Markdown/assets',
    // 是否更新Markdown文件中的图片路径
    updateMarkdownFiles: true,
    // 新的图片引用路径的前缀（相对于Markdown文件）
    newImagePathPrefix: './assets',
    // 是否下载并存储网络图片
    downloadNetworkImages: true  // 将此设置为false可以忽略网络图片
};
*/
const fs = require('fs');
const path = require('path');
const https = require('https');
const http = require('http');
const url = require('url');
const crypto = require('crypto');

// 配置信息
const config = {
    // Markdown文件所在目录
    mdDir: "F:/code/code/Markdown",
    // 图片收集的目标文件夹的根目录
    imageRootDir: 'F:/code/code/Markdown/assets',
    // 是否更新Markdown文件中的图片路径
    updateMarkdownFiles: true,
    // 新的图片引用路径的前缀（相对于Markdown文件）
    newImagePathPrefix: './assets',
    // 是否下载并存储网络图片
    downloadNetworkImages: true
};

// 确保目标根文件夹存在
if (!fs.existsSync(config.imageRootDir)) {
    fs.mkdirSync(config.imageRootDir, { recursive: true });
    console.log(`创建目标根文件夹: ${config.imageRootDir}`);
}

// 获取所有Markdown文件
const getAllMarkdownFiles = (dir) => {
    let results = [];
    const list = fs.readdirSync(dir);

    list.forEach(file => {
        const filePath = path.join(dir, file);
        const stat = fs.statSync(filePath);

        if (stat && stat.isDirectory() && path.basename(filePath) !== path.basename(config.imageRootDir)) {
            // 递归处理子目录，但排除目标图片文件夹
            results = results.concat(getAllMarkdownFiles(filePath));
        } else if (stat && stat.isFile() && path.extname(file).toLowerCase() === '.md') {
            results.push(filePath);
        }
    });

    return results;
};

// 从Markdown内容中提取图片路径
const extractImagePaths = (content, mdFilePath) => {
    const mdDir = path.dirname(mdFilePath);
    // 修改正则表达式，正确处理括号内的所有内容，包括有空格的路径
    const imgRegex = /!\[.*?\]\((.*?)(?:\s+["'][^"']*["'])?\)/g;
    const htmlImgRegex = /<img\s+[^>]*src=["']([^"']+)["'][^>]*>/g;
    const images = [];

    let match;
    // 提取Markdown标准图片语法
    while ((match = imgRegex.exec(content)) !== null) {
        // 直接使用完整捕获的路径，不再分割
        const imgPath = match[1].trim();

        // 判断是否为网络图片
        const isNetworkImage = imgPath.startsWith('http://') || imgPath.startsWith('https://');

        // 根据配置决定是否处理网络图片
        if (!isNetworkImage || (isNetworkImage && config.downloadNetworkImages)) {
            images.push({
                originalReference: imgPath,
                fullMatch: match[0],
                absolutePath: isNetworkImage ? imgPath : path.resolve(mdDir, imgPath),
                isNetworkImage: isNetworkImage
            });
        }
    }

    // 提取HTML图片标签
    while ((match = htmlImgRegex.exec(content)) !== null) {
        const imgPath = match[1].trim();

        // 判断是否为网络图片
        const isNetworkImage = imgPath.startsWith('http://') || imgPath.startsWith('https://');

        // 根据配置决定是否处理网络图片
        if (!isNetworkImage || (isNetworkImage && config.downloadNetworkImages)) {
            images.push({
                originalReference: imgPath,
                fullMatch: match[0],
                absolutePath: isNetworkImage ? imgPath : path.resolve(mdDir, imgPath),
                isNetworkImage: isNetworkImage
            });
        }
    }

    return images;
};

// 为每个Markdown文件创建对应的图片文件夹
const getImageTargetDir = (mdFilePath) => {
    // 从Markdown文件路径创建一个唯一的文件夹名
    const mdFileName = path.basename(mdFilePath, path.extname(mdFilePath));

    // 创建一个以Markdown文件名命名的文件夹
    const targetDir = path.join(config.imageRootDir, mdFileName);

    // 确保目标文件夹存在
    if (!fs.existsSync(targetDir)) {
        fs.mkdirSync(targetDir, { recursive: true });
        console.log(`创建图片文件夹: ${targetDir}`);
    }

    return targetDir;
};

// 获取相对于Markdown文件的新图片路径
const getNewImagePath = (mdFilePath) => {
    // 创建一个相对路径指向特定的图片子文件夹
    const mdFileName = path.basename(mdFilePath, path.extname(mdFilePath));
    return `${config.newImagePathPrefix}/${mdFileName}`;
};

// 下载网络图片
const downloadImage = (imageUrl, targetPath) => {
    return new Promise((resolve, reject) => {
        // 根据URL协议选择http或https模块
        const protocol = url.parse(imageUrl).protocol;
        const client = protocol === 'https:' ? https : http;

        const request = client.get(imageUrl, (response) => {
            // 检查响应状态码
            if (response.statusCode !== 200) {
                reject(new Error(`Failed to download image, status code: ${response.statusCode}`));
                return;
            }

            // 创建写入流
            const file = fs.createWriteStream(targetPath);

            // 将响应数据写入文件
            response.pipe(file);

            // 文件写入完成
            file.on('finish', () => {
                file.close();
                resolve();
            });
        });

        // 处理请求错误
        request.on('error', (err) => {
            // 如果文件已创建，删除它
            if (fs.existsSync(targetPath)) {
                fs.unlinkSync(targetPath);
            }
            reject(err);
        });
    });
};

// 获取网络图片的文件名
const getNetworkImageFileName = (imageUrl) => {
    // 从URL中提取文件名
    const urlPath = url.parse(imageUrl).pathname;
    let fileName = path.basename(urlPath);

    // 如果文件名没有扩展名或扩展名不是常见图片格式，添加默认扩展名
    const ext = path.extname(fileName).toLowerCase();
    const validExtensions = ['.jpg', '.jpeg', '.png', '.gif', '.webp', '.svg', '.bmp', '.tiff'];

    if (!ext || !validExtensions.includes(ext)) {
        fileName += '.jpg'; // 默认添加.jpg扩展名
    }

    return fileName;
};

// 检查两个文件是否相同 (通过比较文件哈希)
const areFilesIdentical = (file1, file2) => {
    try {
        // 如果任一文件不存在，则返回false
        if (!fs.existsSync(file1) || !fs.existsSync(file2)) {
            return false;
        }

        // 计算文件1的MD5哈希
        const hash1 = crypto.createHash('md5');
        const data1 = fs.readFileSync(file1);
        hash1.update(data1);
        const file1Hash = hash1.digest('hex');

        // 计算文件2的MD5哈希
        const hash2 = crypto.createHash('md5');
        const data2 = fs.readFileSync(file2);
        hash2.update(data2);
        const file2Hash = hash2.digest('hex');

        // 比较两个哈希值
        return file1Hash === file2Hash;
    } catch (error) {
        console.error('比较文件时出错:', error);
        return false;
    }
};

// 复制或下载图片到目标文件夹
const processImageToTargetDir = async (image, targetDir) => {
    // 如果是网络图片
    if (image.isNetworkImage) {
        try {
            // 获取网络图片的文件名
            let fileName = getNetworkImageFileName(image.absolutePath);
            const targetPath = path.join(targetDir, fileName);

            // 检查目标路径是否已存在同名文件
            if (fs.existsSync(targetPath)) {
                // 下载图片到临时位置以比较
                const tempPath = path.join(targetDir, `temp_${Date.now()}_${fileName}`);
                await downloadImage(image.absolutePath, tempPath);

                // 比较文件是否相同
                if (areFilesIdentical(targetPath, tempPath)) {
                    // 如果文件内容相同，删除临时文件，使用原文件
                    fs.unlinkSync(tempPath);
                    return fileName;
                } else {
                    // 如果文件内容不同，重命名临时文件
                    const extname = path.extname(fileName);
                    const basename = path.basename(fileName, extname);
                    const timestamp = Date.now();
                    const newFileName = `${basename}_${timestamp}${extname}`;
                    const newTargetPath = path.join(targetDir, newFileName);

                    fs.renameSync(tempPath, newTargetPath);
                    return newFileName;
                }
            } else {
                // 下载图片
                await downloadImage(image.absolutePath, targetPath);
                return fileName;
            }
        } catch (error) {
            console.error(`下载图片失败: ${image.absolutePath}`, error.message);
            return null;
        }
    }
    // 如果是本地图片
    else {
        if (!fs.existsSync(image.absolutePath)) {
            console.warn(`图片不存在: ${image.absolutePath}`);
            // 打印出尝试提取的图片路径，帮助调试
            console.warn(`原始引用路径: ${image.originalReference}`);
            return null;
        }

        const fileName = path.basename(image.absolutePath);
        const targetPath = path.join(targetDir, fileName);

        // 检查目标路径是否已存在同名文件
        if (fs.existsSync(targetPath)) {
            // 比较文件是否相同
            if (areFilesIdentical(image.absolutePath, targetPath)) {
                // 如果文件内容相同，则不需要复制，直接使用原文件名
                console.log(`  图片已存在且内容相同，跳过复制: ${fileName}`);
                return fileName;
            } else {
                // 如果内容不同，则添加时间戳以避免冲突
                const extname = path.extname(fileName);
                const basename = path.basename(fileName, extname);
                const timestamp = Date.now();
                const newFileName = `${basename}_${timestamp}${extname}`;
                const newTargetPath = path.join(targetDir, newFileName);

                fs.copyFileSync(image.absolutePath, newTargetPath);
                return newFileName;
            }
        } else {
            // 目标文件不存在，直接复制
            fs.copyFileSync(image.absolutePath, targetPath);
            return fileName;
        }
    }
};

// 更新Markdown文件内容
const updateMarkdownContent = (content, images, newImagePath) => {
    let updatedContent = content;

    images.forEach(img => {
        if (img.newFileName) {
            const newReference = path.join(newImagePath, img.newFileName).replace(/\\/g, '/');

            // 替换Markdown标准语法中的图片引用
            // 需要转义用于正则表达式的特殊字符
            const mdImgRegex = new RegExp(`!\\[.*?\\]\\(${escapeRegExp(img.originalReference)}(\\s+["'][^"']*["'])?\\)`, 'g');
            updatedContent = updatedContent.replace(mdImgRegex, (match) => {
                // 保留可能存在的title属性
                const titleMatch = match.match(/\(.*\s+["']([^"']*)["']\)/);
                const title = titleMatch ? ` "${titleMatch[1]}"` : '';
                return `![](${newReference}${title})`;
            });

            // 替换HTML标签中的图片引用
            const htmlImgRegex = new RegExp(`<img\\s+[^>]*src=["']${escapeRegExp(img.originalReference)}["'][^>]*>`, 'g');
            updatedContent = updatedContent.replace(htmlImgRegex, (match) => {
                return match.replace(img.originalReference, newReference);
            });
        }
    });

    return updatedContent;
};

// 转义正则表达式中的特殊字符
function escapeRegExp(string) {
    return string.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
}

// 主函数
const main = async () => {
    const mdFiles = getAllMarkdownFiles(config.mdDir);
    console.log(`找到 ${mdFiles.length} 个Markdown文件`);

    let totalImages = 0;
    let processedImages = 0;
    let processedMdFiles = 0;
    let networkImages = 0;
    let localImages = 0;

    for (const mdFile of mdFiles) {
        console.log(`处理文件: ${mdFile}`);
        const content = fs.readFileSync(mdFile, 'utf8');
        const images = extractImagePaths(content, mdFile);

        if (images.length > 0) {
            processedMdFiles++;
            totalImages += images.length;

            // 统计网络图片和本地图片数量
            const networkCount = images.filter(img => img.isNetworkImage).length;
            const localCount = images.length - networkCount;
            networkImages += networkCount;
            localImages += localCount;

            console.log(`  发现 ${images.length} 张图片 (本地: ${localCount}, 网络: ${networkCount})`);

            // 为当前Markdown文件创建专属图片文件夹
            const imageTargetDir = getImageTargetDir(mdFile);
            const newImagePath = getNewImagePath(mdFile);

            // 处理每张图片
            for (const img of images) {
                img.newFileName = await processImageToTargetDir(img, imageTargetDir);
                if (img.newFileName) {
                    processedImages++;
                    const actionWord = img.isNetworkImage ? "下载" : "复制";
                    console.log(`  ${actionWord}图片: ${img.absolutePath} -> ${path.join(imageTargetDir, img.newFileName)}`);
                }
            }

            // 更新Markdown文件内容
            if (config.updateMarkdownFiles) {
                const updatedContent = updateMarkdownContent(content, images, newImagePath);
                fs.writeFileSync(mdFile, updatedContent, 'utf8');
                console.log(`  更新了Markdown文件中的图片引用`);
            }
        }
    }

    console.log('\n总结:');
    console.log(`处理了 ${mdFiles.length} 个Markdown文件`);
    console.log(`其中 ${processedMdFiles} 个文件包含图片`);
    console.log(`发现了 ${totalImages} 张图片 (本地: ${localImages}, 网络: ${networkImages})`);
    console.log(`成功${config.downloadNetworkImages ? "处理" : "复制"}了 ${processedImages} 张图片到各自的文件夹中`);

    if (config.downloadNetworkImages) {
        console.log(`网络图片下载已${config.downloadNetworkImages ? "启用" : "禁用"}`);
    }
};

// 执行主函数
main().catch(error => {
    console.error("执行过程中出现错误:", error);
});