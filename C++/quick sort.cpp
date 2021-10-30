int partition(int low,int high)
{
    int pivot=arr[high];
    int i=low;
    for (int j=low;j<high;j++)
    {
        if (arr[j]<pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}
void quickSort(int low, int high)
{
    if (low<high)
    {
        int p=partition(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }
}
