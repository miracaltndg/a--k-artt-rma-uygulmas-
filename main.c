#include <stdio.h>

// A��k art�rma kullan�c�s�n� temsil eden yap�
struct participant {
  char name[100];
  int bid;
  int bid_count;
};

// struct participant yap�s�n� temsil eden typedef t�r�
typedef struct participant participant;

// Yeni bir ki�i olu�turur ve d�nd�r�r
participant get_participant() {
  participant participant;

  printf("Katilimcinin adini giriniz: ");
  scanf("%s", participant.name);

  printf("Katilimcinin yaptigi teklifi giriniz: ");
  scanf("%d", &participant.bid);

  participant.bid_count = 1;

  return participant;
}

// A��k art�rmaya yeni bir ki�i ekler
void add_participant(participant *participants, int *participant_count, participant new_participant) {
  participants[*participant_count] = new_participant;
  (*participant_count)++;
}

// A��k art�rmada en y�ksek teklifi d�nd�r�r
int get_highest_bid(participant *participants, int participant_count) {
  int highest_bid = participants[0].bid;
int i;
  for ( i = 1; i < participant_count; i++) {
    if (participants[i].bid > highest_bid) {
      highest_bid = participants[i].bid;
    }
  }

  return highest_bid;
}

int main() {
  // A��k art�rmaya kat�lacak ki�i say�s�n� belirtin
  int participant_count;
  printf("Acik artirmaya katilacak katilimci sayisini giriniz: ");
  scanf("%d", &participant_count);

  // A��k art�rmaya kat�lacak ki�ileri tutan bir dizi olu�turun
  participant *participants = (participant *)malloc(participant_count * sizeof(participant));

  // A��k art�rmaya her ki�i i�in bir kat�l�mc� olu�turun
  int i;
  for ( i = 0; i < participant_count; i++) {
    participants[i] = get_participant();
  }

  // A��k art�rmada en y�ksek teklifi bulun
  int highest_bid = get_highest_bid(participants, participant_count);

  // En y�ksek teklifi veren ki�iyi yazd�r�n
  
  for (i = 0; i < participant_count; i++) {
    if (participants[i].bid == highest_bid) {
      printf("En yuksek teklifi %s verdi (%d TL)\n", participants[i].name, highest_bid);
      break;
    }
  }

  free(participants);

  return 0;
}
