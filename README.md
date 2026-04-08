    
# assembly about copy constructor ScavTrap    
    Register	Meaning
    rdi	1st function argument
    rsi	2nd function argument
    rdx	3rd argument    
    rax	return value
    rbp	stack frame base
    rsp	stack pointer
 
 ```text
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
'''
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


# Diamond memory looks like this
DiamondTrap object:

+of        ScavTrap subobject
           +0  vptr (for ScavTrap part)
           +... ScavTrap members

+X + of    FragTrap subobject
           +0  vptr (for FragTrap part)
           +... FragTrap members

+Y + X     (virtual base) ClapTrap
           stored separately