//finding the maximum and minimum of a function


//(INTEGER TERNARY SEARCH)
//--------:CODE:----------


// #include<bits/stdc++.h>
// using namespace std;
// int ternary_search(int low,int high)
// {
//     while((high-low)>=3)
//     {
//         int mid1=low+(high-low)/3;
//         int mid2=high-(high-low)/3;
//         int f1=f(mid1);
//         int f2=f(mid2);
//         if(f1>f2)
//         high=mid2;
//         else if(f2>f1)
//         low=mid1;
//         else
//         {
//             low=mid1;
//             high=mid2;
//         }
//     }
//     int ans=INT_MIN;
//     for(int i=low;i<=high;i++)
//     ans=max(ans,f(i));
//     return ans;
// }
// int main()
// {

// }

//(DECIMAL TERNARY SEARCH)

//-----:CODE:-----


// double ternary_search(double low,double high)
// {
//     const double eps=1e-6;
//     int flag=0;
//     while(high-low>eps)
//     {
//         if(flag==100)
//         break;
//         double mid1=low+(high-low)/3;
//         double mid2=high-(high-low)/3;
//         if(f(mid1)>f(mid2))
//         high=mid2;
//         else if(f(mid1)<f(mid2))
//         low=mid1;
//         else
//         {
//             low=mid1;
//             high=mid2;
//         }
//         flag++;
//     }
//     return f(low);
// }