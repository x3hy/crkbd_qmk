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

# get the start location
start_idx=0
cat "$keyfile" |\
	{ while read line; do
		case "$line" in
			*"[_BASE]"*)
				break
			;;
			*)
				start_idx=$((start_idx+1));
			;;
		esac
	done
	
	# get the end location
	end_idx=$((start_idx+2))
	cat "$keyfile" | tail -n +$end_idx |\
		{ while read line; do
			case "$line" in
				*"["*)
					break
				;;
				*)
					end_idx=$((end_idx+1));
				;;
			esac
		done

		# TODO: make it find this out
		# print out the cut lines:
		sed -n $((start_idx+2)),$((end_idx-3))'p' "$keyfile"
	}
} | {

	# remove extra whitespace and newlines
	keys=""
	while read line; do
		keys="$keys$line"
	done
	
	echo $keys
}
exit 0;

key_to_code(){
	local key=$1

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
					*) key_to_code $key
					;;
				esac
			done

		# Combo product:
		strip_2 $(cat "$keyfile" | grep "COMBO($name" | awk '{print $4}')
	done
