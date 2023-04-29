

void quick_sort(int array[], int left, int right) {
    int index;
    
    if (left < right) {
        index = partition(array, left, right);
        quick_sort(array, left, index - 1);
        quick_sort(array, index + 1, right);
    }
}

int partition(int array[], int left, int right) {
    int pivot, i, j, temp;
    
    pivot = array[right];
    i = left - 1;
    
    for (j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    
    return i + 1;
}
