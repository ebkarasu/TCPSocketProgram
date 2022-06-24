Çalışma şekli:

Projemizde, müşteri programımızdan(TCP_Client.exe) gelen sinyaller sunucu programımızı(TCP_Server.exe) tetikler,
sunucu programımız ise gelen verilere göre veritabanımızda, yani "TCP Socket Programming\TCP_Server\Data.txt" altında bulunan
txt dosyamızda gerekli değişiklikleri yapar, bu sebeple client uygulamasını kullanmaya başlamadan önce TCP_Server uygulamasını 
çalıştırmalıyız aksi takdirde gerekli işlemleri yapmaya çalışırken sunucuya bağlanamayacak ve hata verecektir.

Kullanım:

Client uygulamasını açtığımızda bizden ilk kullanıcı adı ve parola girmemiz istenir, doğru girdiğimizde karşımıza 3 işlem 
seçeneği çıkar: Para gönderme, para yatırma ve para çekme. Para yatırırken yatırmak istediğimiz miktarı gireriz ve bağlantı oluğu 
takdirde para hesabımıza eklenir. Para çekerken yine istediğimiz miktarı gireriz eğer hesabımızda yeterli bakiye varsa çekeriz.
Para gönderme seçeneğinde ise bizden ilk ne kadar para göndermek istediğimizi ister, hesaptaki bakiye yeterliyse sırasıyla göndermek
istediğimiz kişinin kart numarasını, ismini ve soyismini ister, doğru girdiğimiz takdirde işlemi gerçekleştirir.

Veritabanında 7 sütun bulunur, bunlar sırasıyla Banka Şirketi, Kullanıcı Adı, Parola, Kart Numarası(16 Hane), Mevcut Bakiye, İsim ve Soyismi
temsil eder.

Eğer parayı gönderen kişi ile alıcı aynı bankadan ise para hiç bir kesinti olmadan alıcıya ulaşır, eğer farklı bankaya gönderim yapılıyorsa
göndericinin bankasının belirlediği miktarda bir kesinti yapılır bunlar:

- Citigroup Inc. banka şirketi dışarıya yapılan gönderimlerde paradan 15%'lik bir kesim yapar.
- Bank of America banka şirketi dışarıya yapılan gönderimlerde paradan 10%'lik bir kesim yapar.
- Truist Bank banka şirketi dışarıya yapılan gönderimlerde paradan 5%'lik bir kesim yapar.
- JPMorgan Chase & Co banka şirketi dışarıya yapılan gönderimlerde paradan 2.5%'lik bir kesim yapar.

Veritabanını karmaşık olmaması için 13 kişiden oluşturdum, yeterince kişi verisi bulunursa kodda yapılacak ufak bir değişiklikle 500
kişiye kadar bile çıkarılabilir. 

Veritabanımız "TCP Socket Programming\TCP_Server\Data.txt" altındadır bütün değişiklikler orada yapılır "TCP_Server\Database (Backup).txt" 
ise veritabanımızın ilk halidir herhangi bir nedenle istemediğimiz bir işlem yaparsak yedek olarak ilk halinin elimizde bulunması için.





 