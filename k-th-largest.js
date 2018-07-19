var print = console.log;
var _ = require('underscore');

function swap(arr, i, j) {
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}


function partition(arr, start, end, pivot_idx, cb)
{
    var i = 0;
    var j = end -1;
    var k = arr[pivot_idx];

    swap(arr, end, pivot_idx);


    while (i <= j) {
        if (arr[i] <= k) {
            i++;
        } else {
            swap(arr, i, j);
            j--;
       }
    }

    swap(arr, i, end);

    print(" Idx is " + i);

    return cb(arr);
}


if (require.main === module) {
    arr = [ 3,5,67, 8, 9,1,2,40];
    var pivot = arr.length/2;

    print("Pivot element is " + arr[pivot]);

    partition(arr, 0, arr.length-1,
              pivot, function (arr) {
                        _.each( arr, function (elem) { print(elem + " "); })});
}
