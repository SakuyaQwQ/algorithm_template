template<typename iter>
void quick_sort(iter l, iter r) {

	if (l >= r)return;

	iter i = l - 1, j = r + 1;
	auto pivot = *l;

	while (i < j) {
		do i++; while (*i < pivot);
		do j--; while (*j > pivot);
		if (i < j)swap(*i, *j);
	}

	quick_sort(l, j);
	quick_sort(j + 1, r);
}
