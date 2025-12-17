#whether an integer is even or odd

echo "Enter a number"
read num

if [ $((num % 2)) -eq 0 ]
then
    echo -e "Even"
else
    echo -e "Odd"
fi