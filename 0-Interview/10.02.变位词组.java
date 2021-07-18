// 面试题 10.02. 变位词组
// https://leetcode-cn.com/problems/group-anagrams-lcci/

// @simulation
class Solution_1 {

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashMap = new HashMap<>();
        for (String str : strs) {
            char[] cs = str.toCharArray();
            int[] freq = new int[26];
            for (char c : cs) {
                freq[c - 'a']++;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                sb.append((char) (i + 'a')).append(freq[i]);
            }
            String key = sb.toString();
            // List<String> v = hashMap.computeIfAbsent(key, k -> new ArrayList());
            // hashMap.put(key, v);
            List<String> v = hashMap.getOrDefault(key, new ArrayList<String>());
            v.add(str);
        }
        return new ArrayList<>(hashMap.values());
    }
}

// 作者：AC_OIer
// 链接：https://leetcode-cn.com/problems/group-anagrams-lcci/solution/gong-shui-san-xie-tong-ji-bian-wei-ci-de-0iqe/
class Solution_2 {

    public List<List<String>> groupAnagrams(String[] ss) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String s : ss) {
            int[] cnts = new int[26];
            for (char c : s.toCharArray()) {
                cnts[c - 'a']++;
            }
            StringBuilder sb = new StringBuilder();
            for (int i : cnts) {
                sb.append(i + "_");
            }
            String key = sb.toString();
            List<String> list = map.getOrDefault(key, new ArrayList<>());
            list.add(s);
            map.put(key, list);
        }
        for (String key : map.keySet()) {
            ans.add(map.get(key));
        }
        return ans;
    }
}

// @sort
class Solution_3 {

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for (String str : strs) {
            char[] array = str.toCharArray();
            Arrays.sort(array);
            String key = new String(array);
            List<String> list = map.getOrDefault(key, new ArrayList<String>());
            list.add(str);
            map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }
}
