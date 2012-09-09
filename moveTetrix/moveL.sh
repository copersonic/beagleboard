#!/bin/bash

case $# in
	0)
		echo "Error. Move must have an argument. Valid arguments are '-1' (Reverse), '0' (Stop), and '1' (Forward)"
	;;
	1)
		case $1 in
			-1)
				echo -e "10\n600" > ratioR
			;;
			0)
				echo -e "145\n50" > ratioR
			;;
			1)
				echo -e "1600\n5" > ratioR
			;;
			*)
				echo "Argument not recognized. Valid arguments are '-1' (Reverse), '0' (Stop), and '1' (Forward)"
			;;
		esac
	;;
	*)
		echo "Error: Move must have exactly 1 argument."
	;;
esac
