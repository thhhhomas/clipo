# CLIPO

CLIPO é uma implementação simples da técnica Pomodoro para terminal, escrita em C. O programa exibe um cronômetro de foco ou descanso acompanhado por animações ASCII de um gato.

## Funcionalidades

* Temporizador de foco (Focus)
* Temporizador de pausa (Break)
* Animações ASCII de gato durante os ciclos
* Configuração personalizada dos tempos de foco e pausa
* Persistência das configurações em arquivo local
* Interface simples baseada em menus

## Demonstração

### Modo foco

```text
[24:59]      /|_/|
            ('¨' ) \
             `|~|(\_/
```

### Modo descanso

```text
[04:59]         Zzz
             /|_/|
            (_, _)(\__
```

## Compilação

Utilize o GCC para compilar:

```bash
gcc clipo.c -o clipo
```

## Execução

```bash
./clipo
```

## Estrutura de Menus

### Menu Principal

```text
1. Start focusing
2. Configurations
3. Exit
```

### Menu Pomodoro

```text
1. Start focusing
2. Start pause
3. Back to main menu
```

### Menu de Configurações

```text
1. Change focusing time
2. Change pause time
3. Save configurations
4. Back to main menu
```

## Arquivo de Configuração

As configurações são armazenadas em um arquivo chamado:

```text
config
```

Formato:

```text
25;5
```

Onde:

* Primeiro valor = minutos de foco
* Segundo valor = minutos de pausa

Exemplo:

```text
50;10
```

Representa:

* 50 minutos de foco
* 10 minutos de descanso

## Funcionamento

Ao iniciar:

1. O programa tenta ler o arquivo `config`.
2. Caso o arquivo não exista, valores padrão são utilizados.
3. O usuário pode alterar os tempos pelo menu de configurações.
4. As alterações podem ser salvas para uso em futuras execuções.

## Dependências

* GCC
* Biblioteca padrão da linguagem C
* Sistema compatível com POSIX (utiliza `unistd.h` para `sleep()`)
