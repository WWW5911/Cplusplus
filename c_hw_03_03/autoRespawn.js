//這東西請另外開一個分頁用 掛在主頁面 
//////////////////////////這是死亡自動轉生////////////////////////
var looptime = 5000; //一個循環幾毫秒
var actChose = 1; //0是左上第一個 1是右上第一個 2是左上往下數第二個 3是右上往下數第二個 類推
var pointChose = 14; //hp是2 攻擊是4 防禦是6 類推 幸運是18
var lagtime = 5000; //切換頁面的時候等待幾毫秒 有些時候伺服器LAG 就要把這個數值調高 不然可能會抓不到

var point = document.getElementsByClassName("sc-AxgMl llLWDd");
var head = document.getElementsByClassName("sc-fzomME hhnKZs");
(function loop() {
    setTimeout(function () {
        head[1].click();
        setTimeout("head[0].click()",1000);
        setTimeout("test()",2000);
        loop()
    }, looptime+lagtime+2000);
}());
function clickHead0(){
    head[0].click();
}
function test(){
    var isDead = document.getElementsByClassName("sc-fzoKki kNKLJw");
    if(typeof isDead != "undefined" && isDead != null && isDead.length != null && isDead.length > 0){
        console.log("發現死亡");
        head[3].click()
        setTimeout("choseActor()",lagtime);
    }
}
function choseActor(){
    var actor = document.getElementsByClassName("sc-fzoyTs jZUSDr");
    actor[actChose].click();
    for (var i = 0; i < 20; ++i){
        point[pointChose].click();
    }
    setTimeout("clickRespawn()",2000);
}
function clickRespawn(){
    console.log("執行轉生");
    var Respawn = document.getElementsByClassName("sc-AxgMl gRWMlt");
    Respawn[0].click();
}