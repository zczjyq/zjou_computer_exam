// 右侧高度
function markingHeight() {
	var windHeight = $(window).height() - 20;
	var markingH = $("#fanyaMarking").offset().top;
	var personalInfor = $("#personalInfor").innerHeight();
	$('#rightHeight').css({
		'max-height' : windHeight - markingH,
		'top' : markingH
	});// 左侧top
	var ht = windHeight - markingH - personalInfor - 80;
	$('#topicNumberScroll').css('max-height', ht + 'px') // 滚动条高
}

// 右侧滚动条
function topicNumberScroll() {
	$("#topicNumberScroll").niceScroll({
		cursorborder : "",
		cursorwidth : 8,
		cursorcolor : "#e6ecf5",
		boxzoom : false,
		autohidemode : true
	});
	setInterval(function() {
		$("#topicNumberScroll").getNiceScroll().resize(); // 检测滚动条是否重置大小（当窗口改变大小时）
	}, 300)
}

$(function(){
	markingHeight();
	
	topicNumberScroll();
	
	window.onresize = function() {
		markingHeight();
	}
	
	$(".topicNumber_list li").click(function(event) {
		var questionId = $(this).attr("data");
		var markingH = $("#fanyaMarking").offset().top + 10;
		var id = "#question" + questionId;
		$("html,body").animate({
			scrollTop : $(id).offset().top - markingH
		}, 500);
	});
	
	$(window).scroll(function() {
		$(".questionLi").each(function() {
			var divH = $(this).offset().top;
			var questionId = $(this).attr("data");
			if ($(window).scrollTop() > divH - $(this).height() && $(window).scrollTop() < divH) {
				$(".topicNumber_list li").removeClass("current");
				$("#answerSheet" + questionId).addClass("current");
				return false;
			}
		});
	});
});

