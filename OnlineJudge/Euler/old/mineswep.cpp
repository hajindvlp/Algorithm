#include <stdio.h>
#include <strings.h>

char g[12][12];
char t[12][12];

main()
{
	int i, j, x, y, z, n;

	char mc = '.';

	scanf( " %d", &n );
	for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            g[i][j] = t[i][j] = '.';
	for( i = 1; i <= n; i++ ) for( j = 1; j <= n; j++ )
		scanf( " %c", &g[i][j] );
	for( i = 1; i <= n; i++ ) for( j = 1; j <= n; j++ ) {
		scanf( " %c", &t[i][j] );
		if( t[i][j] == 'x' && g[i][j] == '*' ) mc = '*';
	}
	for( i = 1; i <= n; i++ ) {
		for( j = 1; j <= n; j++ ) {
			if( t[i][j] == '.' || g[i][j] == '*' ) {
				putchar( (g[i][j]=='*')?mc:'.' );
			} else {
				x = 0;
				for( y = -1; y <= 1; y++ ) for( z = -1; z <= 1; z++ )
					if( g[i+y][j+z] == '*' ) x++;
				putchar( x+'0' );
			}
		}
		putchar( '\n' );
	}
}
