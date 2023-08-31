/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;
    const result = new Array(n);
    
    // Calculate left products and store them in the result array
    let leftProduct = 1;
    for (let i = 0; i < n; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Calculate right products and multiply with left products
    let rightProduct = 1;
    for (let i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
};

// Example usage
const nums1 = [1, 2, 3, 4];
const result1 = productExceptSelf(nums1);
console.log("Output for nums1:", result1);

const nums2 = [-1, 1, 0, -3, 3];
const result2 = productExceptSelf(nums2);
console.log("Output for nums2:", result2);
