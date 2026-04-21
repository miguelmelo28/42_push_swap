for size in $(seq 1 12); do
    actual=$((2 ** size))
    for disorder in 0 10 19 40 75 100; do
		for algorithm in simple medium complex adaptive; do
			args=$(python3 gen.py $actual $disorder)
			echo "Size: $actual, Disorder: $disorder%"
			result=$(./../push_swap --$algorithm --bench $args | ./checker_linux $args)
			echo "$result"
			if [ "$result" != "OK" ]; then
				echo "Failed! Stopping."
				break 3
			fi
		done
    done
done