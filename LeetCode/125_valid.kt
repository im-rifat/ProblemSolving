class Solution {
    fun isPalindrome(s: String): Boolean {
        val list = ArrayList<Char>()
		
		for(i in s.indices) {
			if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
				list.add(s[i].toLowerCase());
			}
		}
		
		var start: Int = 0
		var end: Int = list.size - 1
		
		while(start <= end) {
			//println(list[start] + " " + list[end])
			if(list[start] != list[end]) {
				return false
			}
			
			start++
			end--
		}
		
		return true;
    }
}