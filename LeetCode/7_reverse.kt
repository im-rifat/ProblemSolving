class Solution {
    fun reverse(x: Int): Int {
        var y: Long = 0
        var n: Long = x.toLong()
        
        var sign: Boolean = true
        
        if(n < 0) {
            sign = false
            n *= -1
        }
        
        val zero: Long = 0
        val ten: Long = 10
        while(n != zero) {
            y *= ten
            y += (n % 10)
            n /= 10
        }
        
        if(y > Integer.MAX_VALUE.toLong()) {
            y = 0
        } else if(y < Integer.MIN_VALUE.toLong()) y = 0
        
        if(sign) return y.toInt()
        
        return (y.toInt()*-1)
    }
}