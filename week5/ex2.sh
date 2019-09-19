if [ ! -f file1.txt ]
then
    touch file1.txt
fi

# input="file1.txt"
# while IFS= read -r line
# do
#   echo "$line"
# done < "$input"

if [ -s file1.txt ]
then
    # tail file1.txt >> file1.txt
    tmp=`tail -1 file1.txt`
    tmp=$((tmp+1))
    echo "$tmp" >> file1.txt

   	#grep  -Eo '^[0-9]+$' file1.txt | tail -1
else
    # echo "File empty"
    echo "1" >> file1.txt
	command >> file1.txt
fi
