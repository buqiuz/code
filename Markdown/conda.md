# conda 配置

## 首先添加环境变量

![](assets/conda/image-20250420142404931.png)

## PowerShell

`conda init`

## 然后配置默认env的路径

`conda config --add envs_dirs F:\miniconda3\envs`

![](assets/conda/abaf2e9f4112423396eaa776443fd0ac.png)

![](assets/conda/c237a8478d184b399b343e251b14630a_1745253018033_1745253110189_1745253114261_1745253157138.png)

## 修改conda 频道

```sh
# 清理冗余配置
conda config --remove-key channels

# 添加 conda-forge 和 defaults
conda config --add channels defaults
conda config --add channels conda-forge
```

## 创建`intelligent_system`环境

```sh
conda deactivate

conda config --add envs_dirs F:\miniconda3\envs

conda remove --name intelligent_system --all

conda create -n intelligent_system python=3.9
conda activate intelligent_system
pip install git+https://github.com/buguroo/pyknow.git

pip install hawksoft.trafficLights
```

