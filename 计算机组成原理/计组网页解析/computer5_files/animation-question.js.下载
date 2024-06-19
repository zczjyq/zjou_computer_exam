function initClock(clockData, clockDom) {
	var timeArray = [];
	for (i in clockData) {
		var item = clockData[i];
		var hour = item.hour;
		var minute = item.minute;
		var data = [];
		data.push(hour);
		data.push(minute);
		timeArray.push(data);
	}
	var dataArray = [];
	for (i in timeArray) {
		var hourData = Number(timeArray[i][0]) * 30 + Number(timeArray[i][1]) / 2;
		var minuteData = Number(timeArray[i][1]) * 6;
		var data = [];
		data.push(hourData);
		data.push(minuteData);
		dataArray.push(data);
	}
	$(clockDom).find(".clock-item").each(function (index, item) {
		$(item).find('.hour-line').css({
			"transform": "rotate(" + dataArray[index][0] + "deg)"
		});
		$(item).find('.minute-line').css({
			"transform": "rotate(" + dataArray[index][1] + "deg)"
		});
	});
}

function initAnswerClock(clockDom, clockData, answerData) {
	var timeArray = [];
	for (i in clockData) {
		var item;
		if (answerData == undefined || answerData.length <= i) {
			item = {"hour": "12", "minute": "00"};
		} else {
			item = answerData[i];
		}
		var hour = item.hour || "";
		var minute = item.minute || "";
		var data = [];
		data.push(hour);
		data.push(minute);
		timeArray.push(data);
	}
	var dataArray = [];
	for (i in timeArray) {
		var hourData = Number(timeArray[i][0]) * 30 + Number(timeArray[i][1]) / 2;
		var minuteData = Number(timeArray[i][1]) * 6;
		var data = [];
		data.push(hourData);
		data.push(minuteData);
		dataArray.push(data);
	}
	$(clockDom).find(".clock-item").each(function (index, item) {
		$(item).find('.hour-line').css({
			"transform": "rotate(" + dataArray[index][0] + "deg)"
		});
		$(item).find('.minute-line').css({
			"transform": "rotate(" + dataArray[index][1] + "deg)"
		});
	});
}

function initDragLineHandle(clockDom) {
	var handlerstart = "mousedown";
	var handlemove = "mousemove";
	var handleend = "mouseup";
	if (this.isPad()) {
		handlerstart = "touchstart";
		handlemove = "touchmove";
		handleend = "touchend";
	}
	var that = this;
	var isDown = false;
	var currentClass;
	var rotArr = [];
	var cX, cY, szoldAngle, values, scale, sin, szangle;
	$(clockDom).find('.drag-clock .m-line').on(handlerstart, function (e) {
		e.preventDefault();
		var currentClockId = $(this).parents(".clock-question").attr("data") || "";
		$("#currentClockId").val(currentClockId);
		isDown = true;
		var _this = this;
		currentClass = this;
		rotArr = [];
		// 圆心坐标
		cX = $(this).parents('.drag-clock').find('.circle').offset().left + 6;
		if (that.isPad()) {
			cY = $(this).parents('.drag-clock').find('.circle').offset().top + 6 - $(
				document).scrollTop();
		} else {
			cY = $(this).parents('.drag-clock').find('.circle').offset().top + 6;
		}
		// 记录时针原本的旋转角度
		szoldAngle = $(this).parent().siblings('.hour-line').css('transform');
		if (szoldAngle == 'none') {
			values = 0;
		} else {
			values = szoldAngle.split('(')[1].split(')')[0].split(',');
			scale = Math.sqrt(values[0] * values[0] + values[1] * values[1]);
			sin = values[1] / scale;
			szangle = Math.round(Math.atan2(values[1], values[0]) * (180 / Math.PI));
		}
	});
	$(document).on(handlemove, function (e) {
		e.preventDefault();
		if (isDown) {
			var mX, mY;
			document.documentElement.style.overflow = "hidden";
			var outer = document.createElement('div');
			var inner = document.createElement('div');
			outer.style.overflow = 'scroll';
			document.body.appendChild(outer);
			outer.appendChild(inner);
			var scrollbarWidth = outer.offsetWidth - inner.offsetWidth;
			document.body.removeChild(outer);
			$(document.body).css("padding-right", scrollbarWidth);
			if (that.isPad()) {
				mX = e.originalEvent.targetTouches[0].clientX;
				mY = e.originalEvent.targetTouches[0].clientY;
			} else {
				mX = e.pageX;
				mY = e.pageY;
			}
			// 根据鼠标移动计算旋转角度
			var result = that.angle(mX, mY, cX, cY);
			var yu = Math.ceil(result / 6);
			var rot = yu * 6;
			var rotNum = Math.ceil(yu / 5);
			// 判断特殊情况不要0
			if (rotNum == 0) {
				rotNum = 1
			}
			// 判断转动几圈定义数组放进滚动的数值
			if (rotArr.length == 0) {
				rotArr.push(rotNum);
			}
			if (rotArr.length > 0 && rotArr[rotArr.length - 1] !== rotNum) {
				rotArr.push(rotNum);
			}
			var rotResult = that.getRotNum(rotArr);
			var hdResult = that.getTwelveNum(rotArr);
			// 分针整的旋转角度
			var zzRot = Math.ceil(360 * (hdResult.sRt - hdResult.nRt) + result);
			// 分针只能一刻度一刻度的转
			var fzRotAngle = Math.ceil(zzRot / 6) * 6;
			// 根据分针的旋转角度得到时针的旋转角度
			var szRotAngle = Math.floor(szangle / 30) * 30 + zzRot / 12;
			$(currentClass).parent().css('transform', `rotate(${fzRotAngle}deg)`);
			$(currentClass).parent().siblings('.hour-line').css('transform', `rotate(${szRotAngle}deg)`);
		}
	});
	$(document).on(handleend, function (e) {
		if (isDown) {
			document.documentElement.style.overflow = "visible";
			$(document.body).css("padding-right", "0px");
			setDragClockData();
		}
		isDown = false;
	});
}

function setDragClockData() {
	var that = this;
	var questionId = $("#currentClockId").val() || "";
	var recordClockData = [];
	$("#clock" + questionId).find(".clock-item").each(function (index, item) {
		var elMinuteRotate = $(item).find('.minute-line').css('transform');
		var elHourRotate = $(item).find('.hour-line').css('transform');
		var minuteAngle = that.getRotateAngle(elMinuteRotate);
		var currentMinuteTime = parseInt(minuteAngle / 6);
		var hourAngle = that.getRotateAngle(elHourRotate);
		var currentHourTime = Math.floor(hourAngle / 30);
		if (currentMinuteTime < 0) {
			currentMinuteTime = currentMinuteTime + 60;
		}
		if (currentHourTime <= 0) {
			currentHourTime = currentHourTime + 12;
		}
		if (currentHourTime < 10) {
			currentHourTime = "0" + currentHourTime;
		}
		if (currentMinuteTime < 10) {
			currentMinuteTime = "0" + currentMinuteTime;
		}
		var data = {};
		data.hour = currentHourTime + "";
		data.minute = currentMinuteTime + "";
		recordClockData.push(data);
	});

	if (recordClockData.length > 0) {
		$("#answer" + questionId).val(JSON.stringify(recordClockData));
		if(typeof answerContentChange == 'function'){
			answerContentChange();
		}
	}
}

function initClockSelect(clockDom) {
	$(clockDom).find(".clock-item .select-time").on("click", function () {
		$(this).find(".select-arrow").toggleClass("rotate180");
		$(this).siblings(".select-down-list").toggleClass("show");
		$(this).parent(".select-item").siblings(".select-item").find(".select-down-list").removeClass("show");
		$(this).parents(".clock-item").siblings(".clock-item").find(".select-down-list").removeClass("show");
	});

	$(clockDom).find(".select-down-list").niceScroll({
		cursorcolor: "#DADFE6",
		cursorwidth: "8px",
		cursorborder: "0",
	});

	$(clockDom).find(".select-down-list").on("click", ".sd-item", function () {
		var data = $(this).html();
		var selectTarget = $(this).parents(".select-item").find(".time-t");
		selectTarget.html(data);
		selectTarget.attr("data", data);

		$(this).addClass("active").siblings().removeClass("active");
		$(this).parent(".select-down-list").toggleClass("show");
		$(this).parents(".select-item").find(".select-arrow").toggleClass("rotate180");
		var clockQuestion = $(this).parent(".select-down-list").parents(".clock-question");
		setSelectClockData(clockQuestion)
	});
}

function setSelectClockData(clockQuestion) {
	var questionId = clockQuestion.attr("data");
	var recordClockData = [];
	clockQuestion.find(".clock-item").each(function (index, item) {
		var currentHourTime = $(item).find(".time-t.select-hour").attr("data") || "";
		var currentMinuteTime = $(item).find(".time-t.select-minute").attr("data") || "";
		var data = {};
		data.hour = currentHourTime + "";
		data.minute = currentMinuteTime + "";
		recordClockData.push(data);
	});

	if (recordClockData.length > 0) {
		$("#answer" + questionId).val(JSON.stringify(recordClockData));
		if(typeof answerContentChange == 'function'){
			answerContentChange();
		}
	}
}

$(function () {
	$(document).on("click", function (e) {
		if ($(e.target).closest(".select-time").length == 0 && $(e.target).closest(".select-down-list").length == 0) {
			$(".select-down-list").each(function () {
				if ($(this).hasClass("show")) {
					$(this).removeClass("show");
					$(this).parent(".select-item").find(".select-arrow").toggleClass("rotate180");
				}
			});
		}
	});
});

// 得到正转的倒转的圈数
function getRotNum(arr) {
	var t_pos = this.findAllOccurrences(arr, 12);
	var zNum = 0;
	var fNum = 0;
	var zR = 0;
	var fR = 0;
	var result = {}
	for (var i = 0; i < t_pos.length; i++) {
		for (var j = 1; j < 12; j++) {
			if (arr[t_pos[i] - j] == 12 - j && arr[t_pos[i] + 1] == 1) {
				zNum++;
			}
			if (arr[t_pos[i] - j] == j) {
				fNum++;
			}
		}
		if (zNum > 10) {
			zNum = 0;
			zR++;
		}
		if (fNum > 10) {
			fNum = 0
			fR++;
		}
	}
	result.zRot = zR
	result.fRot = fR
	return result;
}

// 获取到在12点位置左右晃动的次数
function getTwelveNum(arr) {
	var one_pos = this.findAllOccurrences(arr, 1);
	var twl_pos = this.findAllOccurrences(arr, 12);
	var shun_rot = 0;
	var ni_rot = 0;
	var result = {}
	for (var i = 0; i < one_pos.length; i++) {
		if (arr[one_pos[i] + 1] == 12) {
			ni_rot++;
		}
	}
	for (var j = 0; j < twl_pos.length; j++) {
		if (arr[twl_pos[j] + 1] == 1) {
			shun_rot++;
		}
	}
	result.sRt = shun_rot;
	result.nRt = ni_rot;
	return result;
}

// 找到某个数字在数组中出现的位置下标
function findAllOccurrences(arr, target) {
	var Arr = [];
	arr.forEach((elem, index) => {
		if (elem === target) {
			Arr.push(index);
		}
	});
	return Arr;
};

// 计算旋转的角度
function angle(x, y, centerX, centerY) {
	var radians = Math.atan2(x - centerX, y - centerY);
	return (radians * (180 / Math.PI) * -1) + 180;
};

// 如果后一个数字跟前一个数字不同追加进数组
function noRepeat(arr) {
	var newArr = [...new Set(arr)]; //利用了Set结构不能接收重复数据的特点
	return newArr
};

function isPad() {
	return navigator.userAgent.match(
		/(phone|pad|pod|iPhone|iPod|ios|iPad|Android|Mobile|BlackBerry|IEMobile|MQQBrowser|JUC|Fennec|wOSBrowser|BrowserNG|WebOS|Symbian|Windows Phone)/i
	);
}

function getRotateAngle(value) {
	var values = value.split('(')[1].split(')')[0].split(',');
	var a = values[0];
	var b = values[1];
	var c = values[2];
	var d = values[3];
	var scale = Math.sqrt(a * a + b * b);
	var sin = b / scale;
	var angle = Math.round(Math.atan2(b, a) * (180 / Math.PI));
	return angle;
}