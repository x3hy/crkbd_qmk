#!/bin/sh

if [ ! -n "$1" ]; then
	echo "$0 <keymap.c file>"
	exit 1
fi

keyfile=$1


# removes 2 chars from the end of a string
strip_2(){
	echo "$1" |\
		awk '{ print substr( $0, 1, length($0)-2 ) }'
}

# rips the combo name from a combo line
get_combo_name(){
	strip_2 $(echo "$1" | awk '{print $4}')
}

# For each combo def
cat "$keyfile" | grep "COMBO_END" |\
	while read combo; do
		name=$(get_combo_name "$combo")

		# Combo keys:
		echo "$combo" | sed 's/.*{//' | tr ',' '\n' |\
			while read key; do
				case "$key" in
					*COMBO_END*) break
					;;
					*) echo -n "$key, "
					;;
				esac
			done

		# Combo product:
		echo -n "= "
		strip_2 $(cat "$keyfile" | grep "COMBO($name" | awk '{print $4}')
	done
