1. What is the invariant structure in your program?
Invariant structure dalam program ini adalah alur eksekusi utama yang diatur di dalam kelas RunSession. Struktur ini berisi urutan fase yang tetap dan tidak boleh diubah,
yaitu: menghasilkan input, menghitung base score, menghitung reward, menambahkan uang, menampilkan shop, dan berpindah ke ronde berikutnya. 
Urutan ini harus selalu sama, apa pun perubahan yang dilakukan pada bagian lain dari program. Selain itu, program juga selalu berjalan selama tiga ronde, yang juga termasuk bagian dari invariant.
Dengan menjaga struktur ini tetap, sistem utama menjadi stabil dan tidak mudah rusak ketika ada perubahan pada mekanisme lainnya.

3. Which parts are mutable?
Bagian mutable adalah bagian yang bisa diubah tanpa mengganggu struktur utama program. Dalam program ini, bagian tersebut diwakili oleh beberapa interface, yaitu:

- IInputGenerator: menentukan bagaimana input dihasilkan (misalnya random atau dari user)
- IScoringRule: menentukan bagaimana skor dihitung dari input
- IRewardRule: menentukan bagaimana reward dihitung dari skor

Implementasi dari interface ini bisa diganti atau dimodifikasi sesuai kebutuhan, tanpa harus mengubah alur utama di RunSession. Hal ini membuat program lebih fleksibel dan mudah dikembangkan.

3. When you replaced the InputGenerator, why didn’t RunSession change?
RunSession tidak perlu diubah karena kelas ini tidak bergantung pada implementasi konkret, melainkan pada interface (IInputGenerator).
Artinya, RunSession hanya tahu bahwa ada fungsi generate() yang bisa dipanggil, tanpa peduli bagaimana cara input tersebut dibuat.

Ketika kita mengganti ConsoleInputGenerator dengan RandomInputGenerator, yang berubah hanya implementasinya, bukan cara penggunaannya. 
Hal ini dimungkinkan karena penggunaan konsep dependency injection dan loose coupling, sehingga komponen bisa diganti tanpa harus mengubah sistem utama.

4. What would happen if scoring logic was placed inside RunSession?
Jika logika scoring dimasukkan ke dalam RunSession, maka kelas tersebut akan memiliki lebih dari satu tanggung jawab, yaitu mengatur alur program sekaligus menghitung skor.
Hal ini melanggar prinsip Single Responsibility Principle.

Akibatnya, setiap kali ingin mengubah aturan scoring, kita harus mengubah RunSession, yang seharusnya menjadi bagian inti dari sistem. 
Ini bisa meningkatkan risiko error dan membuat kode menjadi sulit dipelihara. Selain itu, pemisahan antara struktur tetap (invariant) dan bagian yang bisa diubah (mutable) juga akan rusak.
