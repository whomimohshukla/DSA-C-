class BinarySearchInsert {
    // Method to find insert position of x
    searchInsert(arr, x) {
        const n = arr.length;
        let low = 0, high = n - 1;
        let ans = n; // Default index if x > all elements

        while (low <= high) {
            const mid = Math.floor((low + high) / 2);

            if (arr[mid] >= x) {
                ans = mid;    // Potential index
                high = mid - 1; // Check on the left
            } else {
                low = mid + 1;  // Check on the right
            }
        }

        return ans;
    }
}

// Main execution
const arr = [1, 2, 4, 7];
const x = 6;

const obj = new BinarySearchInsert();
const index = obj.searchInsert(arr, x);

console.log("The index is:", index);
