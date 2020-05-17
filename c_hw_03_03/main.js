var target = 0; //目標選擇，0~5
var timeshow = 1; //如果條成0，就不會顯示時間，1的話會顯示時間
var looptime = 10000; //一個循環幾毫秒
var cdtime = 9; //戰鬥的CD，1代表10秒
var intiP = 0; // 初始pause值，剛輸入時就會覆蓋pause，這個東西如果大於0會自動修正成0
var pause = -2;
//0是不暫停，looptime豪秒點一次「「「手動輸入pause = 數字，進行暫停」」」
//=-1的話可以暫停到下次可行動的時候自動點擊，=-2的話每次都會等到可以行動的時候才點擊
//=1或以上的話是暫停輸入的數字的分鐘，然後變成intiP

///////////////////以上是可調整項 下面的不要動///////////////////
var timecount = 0;
var tempcount = 0;
var flag = 0;
var cdCount = 0;
var btn2;
var tempP = 0;
///主程式區塊
intiSet();
(function loop() {
    setTimeout(function () {
    var dt = new Date();
    var min = dt.getMinutes();
    var sec = dt.getSeconds();
    var hour = dt.getHours();
    btn2 = document.getElementsByClassName("sc-AxgMl llLWDd");
    timecount += (looptime/1000);
    cdCount += 1;
    if(cdCount >= 9) cdCount = 0;

    if(pause > 0 && flag == 0){
       flag = 1;
        tempcount = timecount; 
    }
    if(pause > 0)
    if(timecount - tempcount >= pause * 60){
        flag = 0;
        pause = intiP;
    }
    if(pause == 0) click();
    if(pause == -1 && cdCount == 0) {
        click();
        pause = intiP;
    }
    if(pause == -2 && cdCount == 0) click();
    if(timeshow == 1 && pause <= 0) console.log('現在時間 :', hour,' : ',min,' : ',sec," 總時間 : ", timecount,"秒");
    if(timeshow == 1 && pause > 0) console.log('現在時間 :', hour,':',min,':',sec,"總時間 :", timecount,"秒","暫停中,剩",(pause * 60-timecount + tempcount), "秒" );
    loop()
    }, looptime );
}());
function click(){
    if(typeof btn2 != "undefined" && btn2 != null && btn2.length != null && btn2.length > 0)
    btn2[target].click();
}
function intiSet(){
    var dt = new Date();
    var min = dt.getMinutes();
    var sec = dt.getSeconds();
    var hour = dt.getHours();
    btn2 = document.getElementsByClassName("sc-AxgMl llLWDd");
    if(intiP > 0) intiP = 0;
    pause = intiP;
    if(timeshow == 1) console.log('現在時間 :', hour,' : ',min,' : ',sec," 總時間 : ", timecount,"秒");
    click();
}