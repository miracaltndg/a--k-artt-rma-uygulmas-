#include <stdio.h>

// Açık artırma kullanıcısını temsil eden yapı
struct participant {
  char name[100];
  int bid;
  int bid_count;
};

// struct participant yapısını temsil eden typedef türü
typedef struct participant participant;

// Yeni bir kişi oluşturur ve döndürür
participant get_participant() {
  participant participant;

  printf("Katilimcinin adini giriniz: ");
  scanf("%s", participant.name);

  printf("Katilimcinin yaptigi teklifi giriniz: ");
  scanf("%d", &participant.bid);

  participant.bid_count = 1;

  return participant;
}

// Açık artırmaya yeni bir kişi ekler
void add_participant(participant *participants, int *participant_count, participant new_participant) {
  participants[*participant_count] = new_participant;
  (*participant_count)++;
}

// Açık artırmada en yüksek teklifi döndürür
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
  // Açık artırmaya katılacak kişi sayısını belirtin
  int participant_count;
  printf("Acik artirmaya katilacak katilimci sayisini giriniz: ");
  scanf("%d", &participant_count);

  // Açık artırmaya katılacak kişileri tutan bir dizi oluşturun
  participant *participants = (participant *)malloc(participant_count * sizeof(participant));

  // Açık artırmaya her kişi için bir katılımcı oluşturun
  int i;
  for ( i = 0; i < participant_count; i++) {
    participants[i] = get_participant();
  }

  // Açık artırmada en yüksek teklifi bulun
  int highest_bid = get_highest_bid(participants, participant_count);

  // En yüksek teklifi veren kişiyi yazdırın
  
  for (i = 0; i < participant_count; i++) {
    if (participants[i].bid == highest_bid) {
      printf("En yuksek teklifi %s verdi (%d TL)\n", participants[i].name, highest_bid);
      break;
    }
  }

  free(participants);

  return 0;
}
