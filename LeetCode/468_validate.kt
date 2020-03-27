class Solution {
    fun validIPAddress(IP: String): String {
        if(isValidIPv4(IP)) {
			return "IPv4"
		} else if(isValidIPv6(IP)) {
			return "IPv6"
		} else {
			return "Neither"
		}
    }
	
	fun isValidIPv4(IP: String): Boolean {
		val digits = IP.split(".")
		
		if(digits.size != 4) return false
		
		for(n in digits) {
			if(n.length > 3 || n.length == 0) return false
			
			if(n.length != 1 && n[0] == '0') return false
			
			try {
				val num: Int = n.toInt()
				
				if(num > 255 || num < 0) return false
				
				if(n[0] == '-') return false
			} catch(e: NumberFormatException) {
				return false
			}
		}
		return true
	}
	
	fun isValidIPv6(IP: String): Boolean {
		val digits = IP.split(":")
		
		if(digits.size != 8) return false
		
		//println(IP)
		
		for(n in digits) {
			if(n.length > 4 || n.length == 0) return false
			
			for(i in n.indices) {
				if((n[i] >= 'A' && n[i] <= 'F') || (n[i] >= 'a' && n[i] <= 'f') || (n[i] >= '0' && n[i] <= '9')) {
					continue
				}
				
				return false
			}
		}
		return true
	}
}