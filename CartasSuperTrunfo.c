#include <stdio.h>   // Para funções de entrada/saída (printf, scanf)
#include <string.h>  // Para funções de string (strcspn para remover nova linha do fgets)
#include <stdlib.h>  // Para a função system() (para limpar a tela)

// --- Definição da Estrutura para uma Carta de Cidade ---
// Esta estrutura agrupa todas as informações de uma única carta.
struct CartaCidade {
    char estado;              // Uma letra de 'A' a 'H'
    char codigoCarta[5];      // Ex: A01 (4 caracteres + 1 para o terminador null '\0')
    char nomeCidade[50];      // Nome da cidade (capacidade para até 49 caracteres + '\0')
    int populacao;            // Número de habitantes
    float area;               // Área da cidade em quilômetros quadrados (km²)
    float pib;                // Produto Interno Bruto em bilhões de reais
    int numeroPontosTuristicos; // Quantidade de pontos turísticos
};

// --- Função Auxiliar: Limpar o Buffer de Entrada ---
// Essencial para evitar que caracteres indesejados (como a nova linha do Enter)
// afetem a próxima leitura de entrada, especialmente ao alternar entre
// leitura de números (scanf) e leitura de strings (fgets).
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função para Ler os Dados de uma Carta ---
// Recebe um ponteiro para uma struct CartaCidade e o número da carta
// para personalizar as mensagens.
void lerDadosCarta(struct CartaCidade *carta, int numeroCarta) {
    printf("\n--- INSERIR DADOS DA CARTA %d ---\n", numeroCarta);

    // Estado (uma letra)
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado); // O espaço antes de %c consome qualquer '\n' pendente

    limparBuffer(); // Limpa o buffer antes de ler a próxima string

    // Código da Carta (ex: A01)
    printf("Código da Carta (ex: A01): ");
    fgets(carta->codigoCarta, sizeof(carta->codigoCarta), stdin);
    // Remove o caractere de nova linha '\n' que o fgets pode ler
    carta->codigoCarta[strcspn(carta->codigoCarta, "\n")] = '\0'; 

    // Nome da Cidade
    printf("Nome da Cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    // Remove o caractere de nova linha '\n' que o fgets pode ler
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0';

    // População
    printf("População: ");
    scanf("%d", &carta->populacao);

    // Área (em km²)
    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    // PIB (em bilhões de reais)
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    // Número de Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->numeroPontosTuristicos);

    limparBuffer(); // Limpa o buffer após a última leitura de número
}

// --- Função para Exibir os Dados de uma Carta ---
// Recebe um ponteiro constante para uma struct CartaCidade e o número da carta.
// O 'const' indica que a função não modificará os dados da carta.
void exibirDadosCarta(const struct CartaCidade *carta, int numeroCarta) {
    printf("\n--- Carta %d ---\n", numeroCarta);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigoCarta);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);           // %.2f formata para 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", carta->pib); // %.2f formata para 2 casas decimais
    printf("Número de Pontos Turísticos: %d\n", carta->numeroPontosTuristicos);
}

// --- Função Principal (main) do Programa ---
int main() {
    struct CartaCidade carta1; // Declara a primeira carta
    struct CartaCidade carta2; // Declara a segunda carta

    // Limpa a tela do console para uma melhor experiência (opcional)
    // Use "cls" para Windows; para Linux/macOS, use "clear"
    system("cls"); 
    printf("=== CADASTRO DE CARTAS SUPER TRUNFO DE CIDADES ===\n");

    // 1. Lendo os dados da primeira carta
    lerDadosCarta(&carta1, 1);

    // Limpa a tela antes de pedir a segunda carta (opcional)
    system("cls"); 

    // 2. Lendo os dados da segunda carta
    lerDadosCarta(&carta2, 2);

    // Limpa a tela antes de exibir todos os resultados (opcional)
    system("cls"); 
    printf("\n=== INFORMAÇÕES DAS CARTAS CADASTRADAS ===\n");

    // 3. Exibindo os dados da primeira carta
    exibirDadosCarta(&carta1, 1);

    // Adiciona um separador visual entre as cartas para melhor legibilidade
    printf("\n---------------------------------------\n");

    // 4. Exibindo os dados da segunda carta
    exibirDadosCarta(&carta2, 2);

    printf("\n=== FIM DO PROGRAMA ===\n");
    printf("Pressione ENTER para fechar o console...");
    getchar(); // Espera o usuário pressionar Enter antes de fechar

    return 0; // Indica que o programa terminou com sucesso
}
