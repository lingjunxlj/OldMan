package volume_XXII;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Id_3152 {

	public static void main(String[] args) {

		Scanner input = new Scanner (System.in);

		int testCase = input.nextInt();
		int dataSet = 0;

		while ( testCase-- > 0 ) {

			String s = input.next();

			StringTokenizer stok = new StringTokenizer (s, ":");

			int hour = Integer.parseInt(stok.nextToken());
			int minute = Integer.parseInt(stok.nextToken());
			int second = Integer.parseInt(stok.nextToken());

			int hBinary [] = new int [7];
			int mBinary [] = new int [7];
			int sBinary [] = new int [7];

			int index = 0;

			while ( hour != 0 ) {
				hBinary [index++] = hour % 2;
				hour /= 2;
			}

			index = 0;

			while ( minute != 0 ) {
				mBinary [index++] = minute % 2;
				minute /= 2;
			}

			index = 0;

			while ( second != 0 ) {
				sBinary [index++] = second % 2;
				second /= 2;
			}

			System.out.printf("%d ", ++dataSet);

			for ( index = 5; index >= 0; index-- ) {
				System.out.print(hBinary [index]);
				System.out.print(mBinary [index]);
				System.out.print(sBinary [index]);
			}

			System.out.print(" ");

			for ( index = 5; index >= 0; index-- )
				System.out.print(hBinary [index]);
			for ( index = 5; index >= 0; index-- )
				System.out.print(mBinary [index]);
			for ( index = 5; index >= 0; index-- )
				System.out.print(sBinary [index]);

			System.out.println ();
		}
	}
}
