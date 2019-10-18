// var crypto = require('crypto');

// // 秘钥
// var key = "5FXBBDDC6DVPCU84OE7FUMDT6SB47QRF"
// // 填充(ZeroPadding)
// var iv = ''

// // init cipher
// const cipher = crypto.createCipheriv('aes-256-ecb', key, iv);
// // 加密
// var cipherResult = cipher.update("usthooz", 'utf8', 'hex');
// // hex编码
// cipherResult += cipher.final('hex');
// console.log(cipherResult)

// // init cipher
// var decipher = crypto.createDecipheriv('aes-256-ecb', key, iv);
// // 解密
// var decrypted = decipher.update(cipherResult, 'hex', 'utf8');
// decrypted += decipher.final('utf8');
// console.log(decrypted);

var CryptoJS = require("crypto-js");
var key = CryptoJS.enc.Utf8.parse("5FXBBDDC6DVPCU84OE7FUMDT6SB47QRF");

var encrypted = CryptoJS.AES.encrypt("usthooz", key, {
    mode: CryptoJS.mode.ECB,
    padding: CryptoJS.pad.Pkcs7,
});
console.log(encrypted.ciphertext.toString())


var decrypted = CryptoJS.AES.decrypt(encrypted, key, {
    mode: CryptoJS.mode.ECB,
    padding: CryptoJS.pad.Pkcs7,
});
console.log(decrypted.toString(CryptoJS.enc.Utf8));