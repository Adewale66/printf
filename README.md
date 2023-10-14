<h2><a id="NAME" href="#NAME"></a>NAME</h2><pre>
       _printf
</pre>
<h2><a id="LIBRARY" href="#LIBRARY"></a>LIBRARY</h2><pre>
       Standard C library (<i>libc</i>, <i>-lc</i>)
</pre>
<h2><a id="SYNOPSIS" href="#SYNOPSIS"></a>SYNOPSIS</h2><pre>
       <b>#include &lt;main.h&gt;</b>
       <b>int _printf(const char *</b><i>format</i><b>, ...);</b>
</pre>
<h2><a id="DESCRIPTION" href="#DESCRIPTION"></a>DESCRIPTION</h2><pre>
       The function <b>_printf</b> is used to write output to <i>stdout</i>, the standard output stream;
       <br>
       <b>Conversion specifiers</b>
       A character that specifies the type of conversion to be applied.
       The conversion specifiers and their meanings are:
       <b>d</b>, <b>i   </b>The <i>int</i> argument is converted to signed decimal notation.
       <br>
       <b>c      </b>The <i>int</i> argument is converted to an <i>unsigned char</i>, and the resulting character is written.
       <br>
       <b>s      </b>The <i>const char *</i> argument is expected to be a pointer to 
              an array of character type (pointer to a string). Characters from the 
              array are written up to (but not including) a terminating null byte ('\0').
        <br>
       <b>%      </b>A '%' is written.
</pre>
<h2><a id="RETURN_VALUE" href="#RETURN_VALUE"></a>RETURN VALUE</h2><pre>
       Upon successful return, _printf returns the number of
       characters printed (excluding the null byte used to end output to
       strings).
</pre>
<h2><a id="EXAMPLES" href="#EXAMPLES"></a>EXAMPLES</h2><pre>
       To print <i>Hello world</i>
           #include &lt;main.h&gt;
           char *s = "Hello world";
           _printf("%s", s);
</pre>

