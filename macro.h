
//
// EvilC syntax 
//

#define Def(func,ret_type,...) ret_type func(__VA_ARGS__) {
#define End }
#define If(expr) if ( expr ) {
#define Elif(expr) } else if ( expr ) {
#define Else } else {
#define While(expr) while ( expr ) {
