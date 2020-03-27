class Solution {
    fun reverseWords(s: String): String {
        val list = ArrayList<String>()
		
		var str = ""
		
		for(i in s.indices) {
			if(s[i] == ' ') {
				if(str.isEmpty() == false) {
					list.add(str)
					
					str = ""
				}
			} else {
				str += s[i]
			}
		}
		
		if(str.isEmpty() == false) list.add(str)
		var i: Int = list.size - 1
		
		str = ""
		while(i >= 0) {
			if(i != list.size - 1) {
				str += " "
			}
			
			str += list[i];
			i--
		}
		
		return str
    }
}