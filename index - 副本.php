<?php
 echo "</br>";
 //echo "时间1:  ".$time=strtotime(date("Y-m-d 00:00:00",time()+1*24*60*60))."</br>";
 //echo "时间2:  ".$time=strtotime(date("Y-m-d 23:59:59",time()+1*24*60*60))."</br>";
 //echo "时间3:  ".$time=strtotime(date("Y-m-d 00:00:00",time()+2*24*60*60))."</br>";
 //echo "时间4:  ".$time=strtotime(date("Y-m-d 23:59:59",time()+2*24*60*60))."</br>";
 //echo strtotime($time);
// echo $times = strtotime(date("Y-m-d")." 18:00:00",time());
echo date('N', time());
 echo "</br>";
 echo date('w', time());
 echo "</br>";
 echo date("Y-m-d H:i:s",time());
 echo "</br>";
 echo "</br>";
echo $time = strtotime("2015-05-18 15:00:00");
echo "</br>";
//echo $time = strtotime("2015-03-29 08:00:00");
echo "</br>";
/**
 * 计算上一个月的今天，如果上个月没有今天，则返回上一个月的最后一天
 * @param type $time
 * @return type
 */
function last_month_today($time){
    $last_month_time = mktime(date("G", $time), date("i", $time),
                date("s", $time), date("n", $time), 0, date("Y", $time));
    $last_month_t =  date("t", $last_month_time);
    if ($last_month_t < date("j", $time)) {
        return date("Y-m-t H:i:s", $last_month_time);
    }
    return date(date("Y-m", $last_month_time) . "-d H:i:s", $time);
}
echo last_month_today($time);


 