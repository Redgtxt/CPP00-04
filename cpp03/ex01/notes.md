# 📝 Notas - CPP03 ex01: Herança em C++

## 🎯 Conceitos Principais

### Lista de Inicialização `: ClapTrap(...)`

Quando criamos um objeto derivado (`ScavTrap`), precisamos **sempre** inicializar a classe base (`ClapTrap`) usando a lista de inicialização.

#### ✅ Quando usar:
- **Construtores** - OBRIGATÓRIO usar `: ClapTrap(...)`
  ```cpp
  ScavTrap::ScavTrap() : ClapTrap()                    // Construtor padrão
  ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // Construtor parametrizado
  ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) // Copy constructor
  ```

#### ❌ Quando NÃO usar:
- **Operador de atribuição** - Objeto já está construído
- **Funções normais** - Só para construtores

---

## 🏗️ Estrutura de um Objeto Derivado

Quando criamos um `ScavTrap`, **NÃO** criamos dois objetos separados. Criamos **UM único objeto** com duas "partes":

```
ScavTrap objeto
┌─────────────────────┐
│  Parte ClapTrap:    │  ← Construído PRIMEIRO (classe base)
│  - Name             │
│  - Hit_points       │
│  - Energy_points    │
│  - Attack_damage    │
├─────────────────────┤
│  Parte ScavTrap:    │  ← Construído DEPOIS (classe derivada)
│  - métodos próprios │
│  - guard()          │
└─────────────────────┘
```

### 📊 Ordem de Construção:
1. **Primeiro**: Constrói a parte `ClapTrap` (classe base)
2. **Depois**: Constrói a parte `ScavTrap` (classe derivada)

### 💾 Uso de Memória:
```cpp
sizeof(ClapTrap);  // ≈ 32 bytes
sizeof(ScavTrap);  // ≈ 32 bytes (não 64!)
```
**Não há duplicação de memória!** É eficiente.

---

## 🔒 Protected vs Private

### Diferenças:

| Modificador | Classe Base | Classe Derivada | Código Externo |
|------------|-------------|-----------------|----------------|
| `private`   | ✅ Acessa   | ❌ **NÃO** acessa | ❌ Não acessa |
| `protected` | ✅ Acessa   | ✅ **Acessa**     | ❌ Não acessa |
| `public`    | ✅ Acessa   | ✅ Acessa        | ✅ Acessa    |

### Exemplo Prático:

```cpp
class ClapTrap
{
private:
    int secret;        // ❌ ScavTrap NÃO pode acessar
    
protected:
    std::string Name;  // ✅ ScavTrap PODE acessar
    int Hit_points;    // ✅ ScavTrap PODE acessar
    int Energy_points; // ✅ ScavTrap PODE acessar
    int Attack_damage; // ✅ ScavTrap PODE acessar
    
public:
    void attack();     // ✅ Todos podem acessar
};

class ScavTrap : public ClapTrap
{
public:
    void guard()
    {
        this->Name = "Guardian";  // ✅ OK - protected
        this->Hit_points = 100;   // ✅ OK - protected
        this->secret = 42;        // ❌ ERRO - private!
    }
};
```

### Por que ClapTrap usa `protected`?
Para que as classes derivadas (`ScavTrap`, `FragTrap`, etc.) possam acessar diretamente os atributos sem precisar de getters/setters.

---

## 🎓 Resumo

- ✅ Use `: ClapTrap(...)` em **todos os construtores** da classe derivada
- ✅ Herança **não duplica memória** - é um único objeto com partes
- ✅ Use `protected` para atributos que classes derivadas precisam acessar
- ✅ Use `private` para atributos internos que ninguém deve modificar