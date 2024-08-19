
namespace GE
{
    __declspec(dllimport) void test();
}
int main()
{
    GE::test();
    return 0;
}