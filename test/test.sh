for size in 100 1000 2000 5000 10000; do
    actual=$size
    for disorder in 10 19 40 50 75 100; do
		for algorithm in medium complex; do
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