#!/bin/bash
number=0
while read -r line; do
    compare=$((10#$number+1))
    number=$(echo $line | head -c 5 | tail -c 3)
    if [[ 10#$compare -ne 10#$number ]]
    then
        number=$compare
        break
    fi
done < <(find . -maxdepth 1 -type d -regextype sed -regex "\.*/[0-9]\{3\}\-.*" | sort)

next=$((10#$number+1))

if [ -z $1 ]
then
    number=$next
else
    number=$1
fi

check=$(printf "%03d\n" $number)

overwrite=0

echo "Creating boilerplate for problem $number"

while read -r line; do
    current=$(echo $line | head -c 5 | tail -c 3)
    if [[ 10#$current -eq 10#$check ]]
    then
      overwrite=1
      break
    fi
done < <(find . -maxdepth 1 -type d -regextype sed -regex "\.*/[0-9]\{3\}\-.*" | sort)

if [[ $overwrite -eq 1 ]]
then
    echo "Are you sure you want to overwrite?"
    read -n1 -p "Confirm deletion of existing solution $number y/N:" confirm
    echo ""
    if [ "$confirm" = "y" ]
    then
        echo "Okay, overwriting solution $number"
    else
        echo "Okay, quitting"
        exit
    fi
fi

while IFS='' read -r line; do
    current=$(echo "$line" | awk '{print $1}')
    if [[ $number -eq $current ]]
    then
        prefixlen=$((3-($(echo $number | wc -m)-1)))
        line=$(echo "00000000" | head -c $prefixlen)$line #really not needed as it's 1 or 2 but why not
        line=$(sed 's/\t/-/g' <<<$line)
        line=$(sed 's/\ /-/g' <<<$line)
        line=${line::-1}
        echo $line
        mkdir $line
        #find boilerplate/* -exec cat {} | sed 's/#PROBLEM#/'$number'/g' > "$line/$(basename {})"; \;

        find boilerplate/* | while read fn; do out="$line/$(basename $fn)"; cp "$fn" "$out"; sed -i 's/#PROBLEM#/'$number'/g' "$out"; done

        #cat ./boilerplate/boilerplate.c | sed 's/#PROBLEM#/'$number'/g' > $line/main.c

        exit
    fi
done < ./problem-list

echo "Problem not found, update list"
