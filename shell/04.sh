echo "Enter lower range:"
read l
echo "Enter higher range:"
read h

for (( i=$l ; i<=h ; i++))
do
    # echo -e "$i"
    count=0
    for (( j=1 ; j<=i ; j++ ))
    do
        if [ $((i%j)) == 0 ]
        then
        count=$((count+1))
        fi
    done
    if [ $count -eq 2 ]
    then
        echo $i
    fi
done
