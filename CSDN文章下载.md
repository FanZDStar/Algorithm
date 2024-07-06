### CSDN文章下载

1，进入到想要下载的文章界面，按功能键“F12”

2，进入到控制台，输入如下代码

```bash
(function(){
    $("#side").remove();
    $("#comment_title, #comment_list, #comment_bar, #comment_form, .announce, #ad_cen, #ad_bot").remove();
    $(".nav_top_2011, #header, #navigator").remove();
    $(".p4course_target, .comment-box, .recommend-box, #csdn-toolbar, #tool-box").remove();
    $("aside").remove();
    $(".tool-box").remove();
    $("#toolBarBox").remove();
    $("main").css('display','content'); 
	$("main").css('float', 'none'); // 将浮动方式设置为 none，即取消浮动
    $(".option-box").remove();
    $("body").css('min-width',0);
    $(".option-box").remove();
    window.print();
})();
```

