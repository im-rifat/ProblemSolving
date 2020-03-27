class Solution {
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        val ranArray = IntArray(26)
		val magArray = IntArray(26)
		
		for(i in ransomNote.indices) {
			ranArray[ransomNote[i] - 'a']++;
		}
		
		for(i in magazine.indices) {
			magArray[magazine[i] - 'a']++;
		}
		
		for(i in ransomNote.indices) {
			if(ranArray[ransomNote[i] - 'a'] > magArray[ransomNote[i] - 'a']) return false;
		}
		
		return true;
    }
}