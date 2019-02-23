#include <stdio.h>

char g[12][12];
char try[12][12];

main() {
	int i, j, k, x, y, z, n;
	char mc = '.';

	scanf( " %d", &n );
	memset( g, '.', sizeof(g) );
	memset( try, '.', sizeof(try) );
	for( i = 1; i <= n; i++ ) for( j = 1; j <= n; j++ )
		scanf( " %c", &g[i][j] );
	for( i = 1; i <= n; i++ ) for( j = 1; j <= n; j++ ) {
		scanf( " %c", &try[i][j] );
		if( try[i][j] == 'x' && g[i][j] == '*' ) mc = '*';
	}
	for( i = 1; i <= n; i++ ) {
		for( j = 1; j <= n; j++ ) {
			if( try[i][j] == '.' || g[i][j] == '*' ) {
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
