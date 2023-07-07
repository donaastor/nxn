// delete <mylib/tv.h> and any instance of tv::
// the calculation takes about 8 seconds

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <mylib/tv.h>

struct state25{
		// arrays
	char m[25]={
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};
	char h[15]={
		1,0,0,
		0,1,0,
		0,1,0,
		0,0,1,
		0,0,1
	};
	char v[15]={
		1,0,0,
		0,1,0,
		0,1,0,
		0,0,1,
		0,0,1
	};
		// position
	int s=0;
	int sh=0;
	int sv=0;
	static const int ms=24;
		// counter
	int64_t r=0;							// number of solutions
	int64_t tb=0;							// current number
	int64_t tp=282429536481ll;				// current power of 3
	static const int64_t kb=847288609443ll;	// end of counter
		// functions
	inline void remove(){
		int tm=m[s]-1;
		--h[sh*3+tm];
		--v[sv*3+tm];
		tb-=tm*tp;
	};
	inline void add(){
		int tm=m[s]-1;
		++h[sh*3+tm];
		++v[sv*3+tm];
		tb+=tm*tp;
	};
	inline bool check() const{
		int tm=m[s]-1;
		return ((h[sh*3+tm]<=2)&(v[sv*3+tm]<=2));
	};
	inline void next(){
		++s;
		tp/=3;
		++sv;
		if(sv==5){
			sv=0;
			++sh;
		}
	};
	inline void prev(){
		m[s]=0;
		--s;
		tp*=3;
		--sv;
		if(sv==-1){
			sv=4;
			--sh;
		}
	};
	inline void print_table() const{
		printf("1 1 2 2 3 3");
		for(int i=0;i<5;++i){
			printf("\n%d",(i+3)/2);
			for(int j=0;j<5;++j)
				if(i*5+j<=s)
					printf(" %d",m[i*5+j]);
				else printf(" *");
		}
		printf("\n\n");
	};
	inline void print_stats() const{
		printf("\t%.10f  r = %ld\n",tb/(double)kb,r);
	};
};
struct state36{
		// arrays
	char m[36]={
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0
	};
	char h[18]={
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0
	};
	char v[18]={
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0,
		0,0,0
	};
		// position
	int s=0;
	int sh=0;
	int sv=0;
	static const int ms=35;
		// counter
	int64_t r=0;									// number of solutions
	int64_t tb=0;									// current number
	int64_t tp=50031545098999707ll;					// current power of 3
	static const int64_t kb=150094635296999121ll;	// end of counter
		// functions
	inline void remove(){
		int tm=m[s]-1;
		--h[sh*3+tm];
		--v[sv*3+tm];
		tb-=tm*tp;
	};
	inline void add(){
		int tm=m[s]-1;
		++h[sh*3+tm];
		++v[sv*3+tm];
		tb+=tm*tp;
	};
	inline bool check() const{
		int tm=m[s]-1;
		return ((h[sh*3+tm]<=2)&(v[sv*3+tm]<=2));
	};
	inline void next(){
		++s;
		tp/=3;
		++sv;
		if(sv==6){
			sv=0;
			++sh;
		}
	};
	inline void prev(){
		m[s]=0;
		--s;
		tp*=3;
		--sv;
		if(sv==-1){
			sv=5;
			--sh;
		}
	};
	inline void print_table() const{
		for(int i=0;i<6;++i){
			printf("%d",m[i*6]);
			for(int j=1;j<6;++j)
				if(i*6+j<=s)
					printf(" %d",m[i*6+j]);
				else printf(" *");
		}
		printf("\n\n");
	};
	inline void print_stats() const{
		printf("\t%.10f  r = %ld\n",tb/(double)kb,r);
	};
};

int main(){
	state36 st;
	tv::vreme p1=tv::curr();
	for(int i=0;true;++i){
		if(st.m[st.s]<3){
			++st.m[st.s];
			st.add();
			if(st.check()){
				if(st.s==st.ms){
					++st.r;
					st.remove();
				}
				else{
					st.next();
				}
			}
			else{
				st.remove();
			}
		}
		else{
			st.prev();
			if(st.s<0)break;
			st.remove();
		}
		if(i==10000){
			i=0;
			tv::vreme p2=tv::curr();
			if(tv::calc(p1,p2)>500){
				p1=p2;
				st.print_stats();
			}
		}
	}
	printf("r = %ld\n\n",st.r);
	return 0;
}
