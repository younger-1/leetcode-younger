public class BinarySearch {

    public static void main(String[] args) {
        BinarySearch m = new BinarySearch();
        int[] nums = new int[] {1,2,2,4};

        // int a = m.binary_search(nums, 2);        //  1
        // int b = m.binary_search(nums, 3);        // -1

        // int a = m.lower_bound(nums, 2);          // 1
        // int b = m.lower_bound(nums, 3);          // 3
        // int c = m.lower_bound(nums, 5);          // 4

        // int a = m.upper_bound(nums, 2);          // 3
        // int b = m.upper_bound(nums, 3);          // 3
        // int c = m.upper_bound(nums, 5);          // 4

        // int a = m.greater_or_equal(nums, 2);     // 1
        // int b = m.greater_or_equal(nums, 3);     // 3
        // int c = m.greater_or_equal(nums, 5);     // 3
                                               
        // int a = m.greater(nums, 2);              // 3
        // int b = m.greater(nums, 3);              // 3
        // int c = m.greater(nums, 5);              // 3

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }

    int binary_search(int[] nums, int target) {
        int left = 0; 
        int right = nums.length - 1; // 注意

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid; 
            else if (nums[mid] < target)
                left = mid + 1; // 注意
            else if (nums[mid] > target)
                right = mid - 1; // 注意
        }
        return -1;
    }

    
    // Search range: [0, n]
    int lower_bound(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int left = 0;
        int right = nums.length; // 注意

        while (left < right) { // 注意
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid; // 注意
            }
        }
        return left;
    }

    // Search range: [0, n]
    int upper_bound(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int left = 0;
        int right = nums.length;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        return left;
    }

    // Search range: [0, n - 1]
    int greater_or_equal(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] >= target) {
                right = mid;
            }
        }
        return left;
    }

    // Search range: [0, n - 1]
    int greater(int[] nums, int target) {
        if (nums.length == 0) return -1;
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        return left;
    }
}