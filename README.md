    
# assembly about copy constructor ScavTrap    
    Register	Meaning
    rdi	1st function argument
    rsi	2nd function argument
    rdx	3rd argument    
    rax	return value
    rbp	stack frame base
    rsp	stack pointer
 
 
   0x00000000004032f0 <+0>:     push   %rbp
   0x00000000004032f1 <+1>:     mov    %rsp,%rbp
   0x00000000004032f4 <+4>:     sub    $0x30,%rsp
   0x00000000004032f8 <+8>:     mov    %rdi,-0x8(%rbp)
   0x00000000004032fc <+12>:    mov    %rsi,-0x10(%rbp)
   0x0000000000403300 <+16>:    mov    -0x8(%rbp),%rdi
   0x0000000000403304 <+20>:    mov    %rdi,-0x30(%rbp)
   0x0000000000403308 <+24>:    mov    -0x10(%rbp),%rsi
   0x000000000040330c <+28>:    call   0x4025d0 <_ZN8ClapTrapC2ERKS_>
   0x0000000000403311 <+33>:    mov    -0x30(%rbp),%rax
   0x0000000000403315 <+37>:    mov    -0x10(%rbp),%rcx
   0x0000000000403319 <+41>:    mov    0x2c(%rcx),%cl
   0x000000000040331c <+44>:    and    $0x1,%cl
   0x000000000040331f <+47>:    mov    %cl,0x2c(%rax)
   0x0000000000403322 <+50>:    mov    -0x10(%rbp),%rcx
   0x0000000000403326 <+54>:    mov    0x2c(%rcx),%cl
   0x0000000000403329 <+57>:    and    $0x1,%cl
   0x000000000040332c <+60>:    mov    %cl,0x2c(%rax)
   0x000000000040332f <+63>:    mov    $0x406140,%edi
   0x0000000000403334 <+68>:    mov    $0x4041d8,%esi
   0x0000000000403339 <+73>:    call   0x402110 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x000000000040333e <+78>:    mov    %rax,%rcx
   0x0000000000403341 <+81>:    mov    %rcx,-0x28(%rbp)
   0x0000000000403345 <+85>:    jmp    0x40334a <_ZN8ScavTrapC2ERKS_+90>
   0x000000000040334a <+90>:    mov    -0x28(%rbp),%rdi
   0x000000000040334e <+94>:    mov    $0x402090,%esi
   0x0000000000403353 <+99>:    call   0x402120 <_ZNSolsEPFRSoS_E@plt>
   0x0000000000403358 <+104>:   jmp    0x40335d <_ZN8ScavTrapC2ERKS_+109>
   0x000000000040335d <+109>:   add    $0x30,%rsp
   0x0000000000403361 <+113>:   pop    %rbp
   0x0000000000403362 <+114>:   ret    
   0x0000000000403363 <+115>:   mov    -0x30(%rbp),%rdi
   0x0000000000403367 <+119>:   mov    %rax,%rcx
   0x000000000040336a <+122>:   mov    %edx,%eax
   0x000000000040336c <+124>:   mov    %rcx,-0x18(%rbp)
   0x0000000000403370 <+128>:   mov    %eax,-0x1c(%rbp)
   0x0000000000403373 <+131>:   call   0x402560 <_ZN8ClapTrapD2Ev>
   0x0000000000403378 <+136>:   mov    -0x18(%rbp),%rdi
   0x000000000040337c <+140>:   call   0x4021b0 <_Unwind_Resume@plt>

   ## initializer lists (: ClapTrap(other)) are only allowed in constructors — not in operators.


# class FragTrap : public ClapTrap

ClapTrap public members stay public
ClapTrap protected members stay protected
ClapTrap private members are still inaccessible

# class FragTrap : protected ClapTrap

ClapTrap public members become protected
ClapTrap protected members stay protected
Private members still inaccessible

# class FragTrap : private ClapTrap

ClapTrap public → becomes private
ClapTrap protected → becomes private
Private members still inaccessible

# Virtual
 Constructors CANNOT be virtual.
 virtual is used for runtime polymorphism.
 It allows C++ to decide which function to call at runtime, not at compile time.

 ## When a function is virtual:
    C++ creates a hidden table called vtable
    Each object stores a pointer to that table
    At runtime, it looks up the correct function

If this function is overridden in a derived class, use the derived version when called through a base pointer.
## When DO You Need virtual?
    

## Key Rule To Remember
If a class has ANY virtual function, its destructor should almost always be virtual too.

### ex)
ClapTrap* ptr = new ScavTrap();
delete ptr;
this case only ClapTrap destructor called!


# C++ object lifetime rules
    ## derived -> base

## important
    The starting address of ScavTrap is the same as the starting address of its ClapTrap part.


#  ex03
## This is to demonstrate name hiding in multiple inheritance.
    DiamondTrap inherits (Indirectly) from ClapTrap...
    _name must be exactly same as in the ClapTrap base class! otherwise Different variable (not the same memory!)

# memory layout
## class DiamondTrap : public ScavTrap, public FragTrap
### ex) DiamondTrap Dia("Bob");
Address of Dia
[ ScavTrap part ]
    └── ClapTrap (inside ScavTrap)
[ FragTrap part ]
    └── ClapTrap (inside FragTrap)
[ DiamondTrap members ]
    └── name

C++ must construct the object in a strict order:
Virtual base classes (if any)
Direct base classes (in the order they are declared)
Member variables
Constructor body

## important
we have to call base constructor explicitly

# virtual inheritance
    in this subject including just only one ClapTrap it is right now a shared base.

# vtable 
## C++ polymorphic object it has vptr at first address 
    nm Diamond | grep _ZTV 
    p &a
    x/gx &a : to checking memory


    (gdb) x/10gx 0x00007ffff7e299a0
    0x7ffff7e299a0: 0x00007ffff7e1e8b8      0x0000000000000001
    0x7ffff7e299b0: 0x00007ffff7dab7c6      0x0000000000000000
    0x7ffff7e299c0: 0x0000002e00000000      0x000000000000002c
    0x7ffff7e299d0: 0x00007ffff7dad4e0      0x0000000000000000
    0x7ffff7e299e0: 0x00007ffff7dad4e0      0x0000000000000000

    (gdb) info vtbl a
    vtable for 'DiamondTrap' @ 0x7ffff7e299a0 (subobject @ 0x7fffffffd9c0):
    [0]: 0x7ffff7e1e8b8

    vtable for 'FragTrap' @ 0x7ffff7a1ace0 (subobject @ 0x7fffffffd9d0):
    [0]: 0x41bea0


# vptr is almost at starting point it is about virtual funtion so we call it it is polymorphic type!
## and vptr --> vtable  address --> virtual functions in this context it is default destructor!


# DiamondTrap default constructor 
0x00000000004031e0 <+0>:     push   %rbp
   0x00000000004031e1 <+1>:     mov    %rsp,%rbp
   0x00000000004031e4 <+4>:     sub    $0x60,%rsp
   0x00000000004031e8 <+8>:     mov    %rdi,-0x8(%rbp)      rdi = *(rbp - 0x8)
   0x00000000004031ec <+12>:    mov    %rsi,-0x10(%rbp)

   0x00000000004031f0 <+16>:    mov    -0x8(%rbp),%rdi 

## why here store agian it somewhere? because of multiple inheritance 
   0x00000000004031f4 <+20>:    mov    %rdi,-0x30(%rbp)
   0x00000000004031f8 <+24>:    mov    -0x10(%rbp),%rsi
   0x00000000004031fc <+28>:    mov    %rsi,-0x28(%rbp)

   0x0000000000403200 <+32>:    add    $0x8,%rsi

   0x0000000000403204 <+36>:    call   0x404d40 <_ZN8ScavTrapC2Ev>
   0x0000000000403209 <+41>:    mov    -0x30(%rbp),%rdi
   0x000000000040320d <+45>:    mov    -0x28(%rbp),%rsi
   0x0000000000403211 <+49>:    add    $0x10,%rdi
   0x0000000000403215 <+53>:    add    $0x18,%rsi
   0x0000000000403219 <+57>:    call   0x4041f0 <_ZN8FragTrapC2Ev>
   0x000000000040321e <+62>:    jmp    0x403223 <_ZN11DiamondTrapC2Ev+67>
   0x0000000000403223 <+67>:    mov    -0x30(%rbp),%rcx
   0x0000000000403227 <+71>:    mov    -0x28(%rbp),%rdx
   0x000000000040322b <+75>:    mov    (%rdx),%rsi
   0x000000000040322e <+78>:    mov    %rsi,(%rcx)
   0x0000000000403231 <+81>:    mov    0x28(%rdx),%rdi
   0x0000000000403235 <+85>:    mov    (%rcx),%rsi
   0x0000000000403238 <+88>:    mov    -0x18(%rsi),%rsi
   0x000000000040323c <+92>:    mov    %rdi,(%rcx,%rsi,1)
   0x0000000000403240 <+96>:    mov    0x30(%rdx),%rdx
   0x0000000000403244 <+100>:   mov    %rdx,0x10(%rcx)
   0x0000000000403248 <+104>:   add    $0x18,%rcx
   0x000000000040324c <+108>:   mov    %rcx,-0x40(%rbp)

--Type <RET> for more, q to quit, c to continue without paging--
   0x0000000000403250 <+112>:   lea    -0x20(%rbp),%rdi
   0x0000000000403254 <+116>:   mov    %rdi,-0x38(%rbp)
   0x0000000000403258 <+120>:   call   0x4021e0 <_ZNSaIcEC1Ev@plt>
   0x000000000040325d <+125>:   mov    -0x40(%rbp),%rdi
   0x0000000000403261 <+129>:   mov    -0x38(%rbp),%rdx
   0x0000000000403265 <+133>:   mov    $0x406048,%esi
   0x000000000040326a <+138>:   call   0x402ee0
   <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEPKcRKS3_>
   0x000000000040326f <+143>:   jmp    0x403274 <_ZN11DiamondTrapC2Ev+148>
   0x0000000000403274 <+148>:   lea    -0x20(%rbp),%rdi
   0x0000000000403278 <+152>:   call   0x402160 <_ZNSaIcED1Ev@plt>
   0x000000000040327d <+157>:   mov    -0x30(%rbp),%rax
   0x0000000000403281 <+161>:   mov    (%rax),%rcx
   0x0000000000403284 <+164>:   mov    -0x18(%rcx),%rcx
   0x0000000000403288 <+168>:   movl   $0x64,0x28(%rax,%rcx,1)
   0x0000000000403290 <+176>:   mov    (%rax),%rcx
   0x0000000000403293 <+179>:   mov    -0x18(%rcx),%rcx
   0x0000000000403297 <+183>:   movl   $0x32,0x2c(%rax,%rcx,1)
   0x000000000040329f <+191>:   mov    (%rax),%rcx
   0x00000000004032a2 <+194>:   mov    -0x18(%rcx),%rcx
   0x00000000004032a6 <+198>:   movl   $0x1e,0x30(%rax,%rcx,1)
   0x00000000004032ae <+206>:   mov    $0x409140,%edi
   0x00000000004032b3 <+211>:   mov    $0x4061e7,%esi
   0x00000000004032b8 <+216>:   call   0x402120 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x00000000004032bd <+221>:   mov    %rax,%rcx
   0x00000000004032c0 <+224>:   mov    %rcx,-0x48(%rbp)
   0x00000000004032c4 <+228>:   jmp    0x4032c9 <_ZN11DiamondTrapC2Ev+233>
   0x00000000004032c9 <+233>:   mov    -0x48(%rbp),%rdi
   0x00000000004032cd <+237>:   mov    -0x30(%rbp),%rsi
   0x00000000004032d1 <+241>:   add    $0x18,%rsi
   0x00000000004032d5 <+245>:   call   0x402100 <_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@plt>
   0x00000000004032da <+250>:   mov    %rax,%rcx
   0x00000000004032dd <+253>:   mov    %rcx,-0x50(%rbp)
   0x00000000004032e1 <+257>:   jmp    0x4032e6 <_ZN11DiamondTrapC2Ev+262>
   0x00000000004032e6 <+262>:   mov    -0x50(%rbp),%rdi
   0x00000000004032ea <+266>:   mov    $0x4061f4,%esi
   0x00000000004032ef <+271>:   call   0x402120 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x00000000004032f4 <+276>:   mov    %rax,%rcx
   0x00000000004032f7 <+279>:   mov    %rcx,-0x58(%rbp)
   0x00000000004032fb <+283>:   jmp    0x403300 <_ZN11DiamondTrapC2Ev+288>
   0x0000000000403300 <+288>:   mov    -0x58(%rbp),%rdi
   0x0000000000403304 <+292>:   mov    $0x402090,%esi
   0x0000000000403309 <+297>:   call   0x402140 <_ZNSolsEPFRSoS_E@plt>
   0x000000000040330e <+302>:   jmp    0x403313 <_ZN11DiamondTrapC2Ev+307>
   0x0000000000403313 <+307>:   add    $0x60,%rsp
   0x0000000000403317 <+311>:   pop    %rbp
   0x0000000000403318 <+312>:   ret    
   0x0000000000403319 <+313>:   mov    %rax,%rcx
   0x000000000040331c <+316>:   mov    %edx,%eax
   0x000000000040331e <+318>:   mov    %rcx,-0x18(%rbp)
   0x0000000000403322 <+322>:   mov    %eax,-0x1c(%rbp)
   0x0000000000403325 <+325>:   jmp    0x40336e <_ZN11DiamondTrapC2Ev+398>
   0x000000000040332a <+330>:   mov    %rax,%rcx
--Type <RET> for more, q to quit, c to continue without paging--
   0x000000000040332d <+333>:   mov    %edx,%eax
   0x000000000040332f <+335>:   mov    %rcx,-0x18(%rbp)
   0x0000000000403333 <+339>:   mov    %eax,-0x1c(%rbp)
   0x0000000000403336 <+342>:   lea    -0x20(%rbp),%rdi
   0x000000000040333a <+346>:   call   0x402160 <_ZNSaIcED1Ev@plt>
   0x000000000040333f <+351>:   jmp    0x403359 <_ZN11DiamondTrapC2Ev+377>
   0x0000000000403344 <+356>:   mov    -0x40(%rbp),%rdi
   0x0000000000403348 <+360>:   mov    %rax,%rcx
   0x000000000040334b <+363>:   mov    %edx,%eax
   0x000000000040334d <+365>:   mov    %rcx,-0x18(%rbp)
   0x0000000000403351 <+369>:   mov    %eax,-0x1c(%rbp)
   0x0000000000403354 <+372>:   call   0x4020a0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>
   0x0000000000403359 <+377>:   mov    -0x28(%rbp),%rsi
   0x000000000040335d <+381>:   mov    -0x30(%rbp),%rdi
   0x0000000000403361 <+385>:   add    $0x10,%rdi
   0x0000000000403365 <+389>:   add    $0x18,%rsi
   0x0000000000403369 <+393>:   call   0x4043d0 <_ZN8FragTrapD2Ev>
   0x000000000040336e <+398>:   mov    -0x28(%rbp),%rsi
   0x0000000000403372 <+402>:   mov    -0x30(%rbp),%rdi
   0x0000000000403376 <+406>:   add    $0x8,%rsi
   0x000000000040337a <+410>:   call   0x405260 <_ZN8ScavTrapD2Ev>
   0x000000000040337f <+415>:   mov    -0x18(%rbp),%rdi
   0x0000000000403383 <+419>:   call   0x4021d0 <_Unwind_Resume@plt>