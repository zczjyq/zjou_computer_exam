function validateAudioPlayTimes(frameElement) {
    var frameElementObj = $(frameElement);
    var mid = frameElementObj.attr('mid') || '';
    var objectid = frameElementObj.attr('data') || '';
    var limitTimes = frameElementObj.attr('playtimeslimit') || 0;
    if (mid == '' || objectid == '' || limitTimes <= 0) {
        return;
    }

    var questionId = $(frameElement).parents('.singleQuesId').attr('data') || '';
    var url = _HOST_CP2_ + '/work/audio-playtimes?questionId=' + questionId + '&mid=' + mid
        + '&objectid=' + objectid + '&limitTimes=' + limitTimes;

    var courseId = $("#courseId").val();
    var classId = $("#classId").val();
    var cpi = $("#cpi").val();
    var workId = $("#workId").val();
    var answerId = $("#answerId").val();
    var device = $("#fromDevice").val();

    $.ajax({
        url: url,
        type: "post",
        data: {
            "courseId": courseId,
            "classId": classId,
            "cpi": cpi,
            "workId": workId,
            "answerId": answerId,
            "questionId": questionId,
            "objectid": objectid,
            "mid": mid,
            "limitTimes": limitTimes
        },
        dataType: "json",
        success: function (result) {
            var status = result.status;
            if (status == 0) {
                frameElement.contentWindow.stopAudioPlay();
                if ("mooc2" == device) {
                    $('#audioLimitTimesWinNew .audioLimitTimesTip span').text(limitTimes);
                    $("#audioLimitTimesWinNew").fullFadeIn();
                } else if ("mooc1" == device) {
                    $('.audioLimitTimesTip span').text(limitTimes);
                    WAY.box.show({'divid': 'audioLimitTimesWin'});
                } else if ("mobile" == device) {
                    var contentTip = '<p style="position:relative;top:20%;text-align:center;">此附件仅支持打开 <span style="color:#0099ff">'
                        + limitTimes + '</span> 次，你已打开 <span style="color:#0099ff">' + limitTimes + '</span> 次，不能再次打开</p>';
                    var okTip = EXAM_I18N_Config.confirmKnow;
                    openNoticeConfirm('', contentTip, okTip);
                }
            }
        }
    });
}