#!/bin/sh
sum() {
#    echo "INFN"
    SUM=0
    for n in $LINE; do
#        echo "Next value $n"
        if ! [[ "$n" =~ ^[0-9]+$ ]];then
            echo "Error" &>/dev/null
            SUM=0
            break
        else
            (( SUM += n )) &>/dev/null
        fi
    done
#    echo $SUM
#    echo "FN Finished"
}
read LINE
#echo "READ FIRST LINE"
sum $LINE
$? &>/dev/null
#echo "FN EXITED"
SUM1=$SUM
#echo "SUM1 is $SUM1"
read LINE
#echo "READ SECOND LINE"
sum $LINE
$? &>/dev/null
SUM2=$SUM
#echo "SECOND FN FIN"
#echo $SUM2
if [ $SUM1 -eq $SUM2 ]; then
    echo "EQUAL"
else
    echo "NOT EQUAL"
fi
echo "PROG FINISHED"
