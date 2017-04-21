
int main (){

  	int arr = [5,6,3,7,3,7,,4,7,23,6];

  	mergeSort(arr, 0, arr.length()-1);

	return 0;
}


void mergesort (int *arr, int l, int r){

	int m = (l + r)/2;

	if (l < r){

		mergesort(arr, l, m);
		mergesort(arr, m+1, r);

		merge(arr, l, m, r);
	}

	return;
}

void merge(int *arr, int l, int m, int r){
	int ret [r+1];

	int i = l;
	int j = m+1;
	int cur = l;

	while (i < l && j < r){
		if (arr[i] < arr[j]){
			ret[cur] = arr[i];
			i++;
		}
		else {
			ret[cur]= arr[j];
			j++
		}
		cur++;
	}

	while ( i < l){
		ret[cur] = arr[i];
		i++;
		cur++;
	}
	while ( j < r){
		ret[cur] = arr[j];
		j++;
		cur++;
	}

	for (int i = 0; i < r-l ; i++){

		arr[i] = ret[i];
	}

	delete [] ret;

	return;

}



