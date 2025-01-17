for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./Dynamic-Range-Sum-Queries < in) <(./correct < in) || break
done
