import{o as j,a as q,e as f,B as K,X as Q,d as F,j as d,c as m,ah as D,k as J,ac as Y,am as Z,S as ee,ab as te,aj as O,a5 as R,an as ne,u as H,ao as V,ap as ae,b as P,w as se,t as U,a3 as $,a8 as le,a9 as oe,a1 as ue}from"./index-35141ee5.js";import{E as ie}from"./el-avatar-948f01f8.js";var z=F({name:"vue3-danmaku",components:{},props:{danmus:{type:Array,required:!0,default:()=>[]},channels:{type:Number,default:0},autoplay:{type:Boolean,default:!0},loop:{type:Boolean,default:!1},useSlot:{type:Boolean,default:!1},debounce:{type:Number,default:100},speeds:{type:Number,default:200},randomChannel:{type:Boolean,default:!1},fontSize:{type:Number,default:18},top:{type:Number,default:4},right:{type:Number,default:0},isSuspend:{type:Boolean,default:!1},extraStyle:{type:String,default:""}},emits:["list-end","play-end","dm-over","dm-out","update:danmus"],setup(n,{emit:u,slots:x}){let o=d(document.createElement("div")),a=d(document.createElement("div"));const r=d(0),h=d(0);let p=0;const B=d(0),c=d(0),_=d(0),N=d(!1),b=d(!1),k=d({}),i=function(s,l,e="modelValue",t){return m({get:()=>s[e],set:w=>{l(`update:${e}`,t?t(w):w)}})}(n,u,"danmus"),v=D({channels:m(()=>n.channels||B.value),autoplay:m(()=>n.autoplay),loop:m(()=>n.loop),useSlot:m(()=>n.useSlot),debounce:m(()=>n.debounce),randomChannel:m(()=>n.randomChannel)}),y=D({height:m(()=>c.value),fontSize:m(()=>n.fontSize),speeds:m(()=>n.speeds),top:m(()=>n.top),right:m(()=>n.right)});function I(){M(),n.isSuspend&&function(){let s=[];a.value.addEventListener("mouseover",l=>{let e=l.target;e.className.includes("dm")||(e=e.closest(".dm")||e),e.className.includes("dm")&&(s.includes(e)||(u("dm-over",{el:e}),e.classList.add("pause"),s.push(e)))}),a.value.addEventListener("mouseout",l=>{let e=l.target;e.className.includes("dm")||(e=e.closest(".dm")||e),e.className.includes("dm")&&(u("dm-out",{el:e}),e.classList.remove("pause"),s.forEach(t=>{t.classList.remove("pause")}),s=[])})}(),v.autoplay&&A()}function M(){if(r.value=o.value.offsetWidth,h.value=o.value.offsetHeight,r.value===0||h.value===0)throw new Error("获取不到容器宽高")}function A(){b.value=!1,p||(p=setInterval(()=>function(){if(!b.value&&i.value.length)if(_.value>i.value.length-1){const s=a.value.children.length;v.loop&&(s<_.value&&(u("list-end"),_.value=0),T())}else T()}(),v.debounce))}function T(s){const l=v.loop?_.value%i.value.length:_.value,e=s||i.value[l];let t=document.createElement("div");v.useSlot?t=function(w,g){return Z({render:()=>ee("div",{},[x.dm&&x.dm({danmu:w,index:g})])}).mount(document.createElement("div"))}(e,l).$el:(t.innerHTML=e,t.setAttribute("style",n.extraStyle),t.style.fontSize=`${y.fontSize}px`,t.style.lineHeight=`${y.fontSize}px`),t.classList.add("dm"),a.value.appendChild(t),t.style.opacity="0",te(()=>{y.height||(c.value=t.offsetHeight),v.channels||(B.value=Math.floor(h.value/(y.height+y.top)));let w=function(g){let C=[...Array(v.channels).keys()];v.randomChannel&&(C=C.sort(()=>.5-Math.random()));for(let S of C){const L=k.value[S];if(!L||!L.length)return k.value[S]=[g],g.addEventListener("animationend",()=>k.value[S].splice(0,1)),S%v.channels;for(let E=0;E<L.length;E++){const X=G(L[E])-10;if(X<=.88*(g.offsetWidth-L[E].offsetWidth)||X<=0)break;if(E===L.length-1)return k.value[S].push(g),g.addEventListener("animationend",()=>k.value[S].splice(0,1)),S%v.channels}}return-1}(t);if(w>=0){const g=t.offsetWidth,C=y.height;t.classList.add("move"),t.dataset.index=`${l}`,t.style.opacity="1",t.style.top=w*(C+y.top)+"px",t.style.width=g+y.right+"px",t.style.setProperty("--dm-scroll-width",`-${r.value+g}px`),t.style.left=`${r.value}px`,t.style.animationDuration=r.value/y.speeds+"s",t.addEventListener("animationend",()=>{Number(t.dataset.index)!==i.value.length-1||v.loop||u("play-end",t.dataset.index),a.value&&a.value.removeChild(t)}),_.value++}else a.value.removeChild(t)})}function G(s){const l=s.offsetWidth||parseInt(s.style.width),e=s.getBoundingClientRect().right||a.value.getBoundingClientRect().right+l;return a.value.getBoundingClientRect().right-e}function W(){clearInterval(p),p=0,_.value=0}return J(()=>{I()}),Y(()=>{W()}),{container:o,dmContainer:a,hidden:N,paused:b,danmuList:i,getPlayState:function(){return!b.value},resize:function(){M();const s=a.value.getElementsByClassName("dm");for(let l=0;l<s.length;l++){const e=s[l];e.style.setProperty("--dm-scroll-width",`-${r.value+e.offsetWidth}px`),e.style.left=`${r.value}px`,e.style.animationDuration=r.value/y.speeds+"s"}},play:A,pause:function(){b.value=!0},stop:function(){k.value={},a.value.innerHTML="",b.value=!0,N.value=!1,W()},show:function(){N.value=!1},hide:function(){N.value=!0},reset:function(){c.value=0,I()},add:function(s){if(_.value===i.value.length)return i.value.push(s),i.value.length-1;{const l=_.value%i.value.length;return i.value.splice(l,0,s),l+1}},push:function(s){return i.value.push(s),i.value.length-1},insert:T}}});const de={ref:"container",class:"vue-danmaku"};(function(n,u){u===void 0&&(u={});var x=u.insertAt;if(n&&typeof document<"u"){var o=document.head||document.getElementsByTagName("head")[0],a=document.createElement("style");a.type="text/css",x==="top"&&o.firstChild?o.insertBefore(a,o.firstChild):o.appendChild(a),a.styleSheet?a.styleSheet.cssText=n:a.appendChild(document.createTextNode(n))}})(`.vue-danmaku {
  position: relative;
  overflow: hidden;
}
.vue-danmaku .danmus {
  position: absolute;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  opacity: 0;
  -webkit-transition: all 0.3s;
  transition: all 0.3s;
}
.vue-danmaku .danmus.show {
  opacity: 1;
}
.vue-danmaku .danmus.paused .dm.move {
  animation-play-state: paused;
}
.vue-danmaku .danmus .dm {
  position: absolute;
  font-size: 20px;
  color: #ddd;
  white-space: pre;
  transform: translateX(0);
  transform-style: preserve-3d;
}
.vue-danmaku .danmus .dm.move {
  will-change: transform;
  animation-name: moveLeft;
  animation-timing-function: linear;
  animation-play-state: running;
}
.vue-danmaku .danmus .dm.pause {
  animation-play-state: paused;
  z-index: 100;
}
@keyframes moveLeft {
  from {
    transform: translateX(0);
  }
  to {
    transform: translateX(var(--dm-scroll-width));
  }
}
@-webkit-keyframes moveLeft {
  from {
    -webkit-transform: translateX(0);
  }
  to {
    -webkit-transform: translateX(var(--dm-scroll-width));
  }
}`),z.render=function(n,u,x,o,a,r){return j(),q("div",de,[f("div",{ref:"dmContainer",class:K(["danmus",{show:!n.hidden},{paused:n.paused}])},null,2),Q(n.$slots,"default")],512)},z.__file="src/lib/Danmaku.vue";const re=n=>O.post("/treeHole/auth/addTreeHole",JSON.stringify({content:n}),{method:"post"}),ce=()=>O.get("/treeHole/getTreeHoleList",{method:"get"}),me=n=>(le("data-v-ae2a90ac"),n=n(),oe(),n),pe={class:"container"},ve={class:"content_container"},fe=me(()=>f("div",null,"树洞",-1)),he={class:"barrage_container"},ye=F({__name:"index",setup(n){const u=d([]),x=d(!1),o=d("");J(()=>{r()});function a(){if(o.value===""){$.warning("请输入内容");return}re(o.value).then(h=>{h.code===200?($.success("添加成功"),r(),o.value=""):$.error(h.msg)})}function r(){ce().then(h=>{h.code===200&&(u.value=h.data)})}return(h,p)=>{const B=ie;return j(),q("div",pe,[f("div",ve,[fe,f("div",null,[R(f("input",{"onUpdate:modelValue":p[0]||(p[0]=c=>V(o)?o.value=c:null),onFocus:p[1]||(p[1]=c=>x.value=!0),type:"text",placeholder:"在这里留下自己的足迹吧..."},null,544),[[ne,H(o)]]),R(f("button",{onClick:a},"提交",512),[[ae,H(x)]])])]),P(H(z),{debounce:3e3,"random-channel":"",speeds:80,channels:5,"is-suspend":"",danmus:H(u),"onUpdate:danmus":p[2]||(p[2]=c=>V(u)?u.value=c:null),"use-slot":"",loop:"",style:{height:"100vh",width:"100vw"}},{dm:se(({danmu:c})=>[f("div",he,[f("div",null,[P(B,{src:c.avatar},null,8,["src"])]),f("div",null,[f("span",null,U(c.nickname)+"：",1),f("span",null,U(c.content),1)])])]),_:1},8,["danmus"])])}}});const xe=ue(ye,[["__scopeId","data-v-ae2a90ac"]]);export{xe as default};
