//#include<iostream>
//#include<string>
//using namespace std;
//
//struct A {
//	int start;
//	int end;
//};
//int samenum(string str1, string str2) {
//	int count = 0;
//	for (int i = 0; i < str1.size(); ++i) {
//		if (str1[i] == str2[i])
//			++count;
//	}
//	return count;
//}
//
//int AnswerNum(int n, int k, string str1, string str2) {
//	int same = samenum(str1, str2);
//	A answer;
//	if (same >= k)
//		answer.end = k + (n - same);
//	else
//		answer.end = same + (n - k);
//	
//	if (k - (n - same) >= 0) 
//		answer.start = 0;
//	else
//		answer.start = k - (n - same);
//	
//
//}