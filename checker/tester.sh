#!/bin/sh

echo "start test"
echo "test 1 2 3 4 5"
./push_swap 1 2 3 4 5 | wc -l

echo "test 1 2 3 5 4"
./push_swap 1 2 3 5 4 | wc -l

echo "test 1 2 4 3 5"
./push_swap 1 2 3 4 5 | wc -l

echo "test 1 2 4 5 3"
./push_swap 1 2 4 3 5 | wc -l

echo "test 1 2 5 4 3"
./push_swap 1 2 5 4 3 | wc -l

echo "test 1 2 5 3 4"
./push_swap 1 2 5 3 4 | wc -l

echo "test 1 3 4 5 2"
./push_swap 1 3 4 5 2 | wc -l

echo "test 1 3 4 2 5"
./push_swap 1 3 4 2 5 | wc -l

echo "test 1 3 5 4 2"
./push_swap 1 3 5 4 2 | wc -l

echo "test 1 3 5 2 4"
./push_swap 1 3 5 2 4 | wc -l

echo "test 1 3 4 2 5"
./push_swap 1 3 4 2 5 | wc -l

echo "test 1 3 4 5 2"
./push_swap 1 3 4 5 2 | wc -l

echo "test 1 4 5 3 2"
./push_swap 1 4 5 3 2 | wc -l

echo "test 1 4 5 2 3"
./push_swap 1 4 5 2 3 | wc -l

echo "test 1 4 3 2 5"
./push_swap 1 4 3 2 5 | wc -l

echo "test 1 4 3 5 2"
./push_swap 1 4 3 5 2 | wc -l

echo "test 1 4 2 5 3"
./push_swap 1 4 2 5 3 | wc -l

echo "test 1 4 2 3 5"
./push_swap 1 4 2 3 5 | wc -l

echo "test 1 5 4 3 2"
./push_swap 1 5 4 3 2 | wc -l

echo "test 1 5 4 2 3"
./push_swap 1 5 4 2 3 | wc -l

echo "test 1 5 3 2 4"
./push_swap 1 5 3 2 4 | wc -l

echo "test 1 5 3 4 2"
./push_swap 1 5 3 4 2 | wc -l

echo "test 1 5 2 4 3"
./push_swap 1 5 2 4 3 | wc -l

echo "test 1 5 2 3 4"
./push_swap 1 5 2 3 4 | wc -l

echo "test 2 3 4 5 1"
./push_swap 2 3 4 5 1 | wc -l

echo "test 2 3 4 1 5"
./push_swap 2 3 4 1 5 | wc -l

echo "test 2 3 5 1 4"
./push_swap 2 3 5 1 4 | wc -l

echo "test 2 3 5 4 1"
./push_swap 2 3 5 4 1 | wc -l

echo "test 2 3 1 5 4"
./push_swap 2 3 1 5 4 | wc -l

echo "test 2 3 1 4 5"
./push_swap 2 3 1 4 5 | wc -l

echo "test 2 1 3 4 5"
./push_swap 2 1 3 4 5 | wc -l

echo "test 2 1 3 5 4"
./push_swap 2 1 3 5 4 | wc -l

echo "test 2 1 4 5 3"
./push_swap 2 1 4 5 3 | wc -l

echo "test 2 1 4 3 5"
./push_swap 2 1 4 3 5 | wc -l

echo "test 2 1 5 3 4"
./push_swap 2 1 5 3 4 | wc -l

echo "test 2 1 5 4 3"
./push_swap 2 1 5 4 3 | wc -l

echo "test 2 5 1 4 3"
./push_swap 2 5 1 4 3 | wc -l

echo "test 2 5 1 3 4"
./push_swap 2 5 1 3 4 | wc -l

echo "test 2 5 4 3 1"
./push_swap 2 5 4 3 1 | wc -l

echo "test 2 5 4 1 3"
./push_swap 2 5 4 1 3 | wc -l

echo "test 2 5 3 1 4"
./push_swap 2 5 3 1 4 | wc -l

echo "test 2 5 3 4 1"
./push_swap 2 5 3 4 1 | wc -l

echo "test 2 4 5 1 3"
./push_swap 2 4 5 1 3 | wc -l

echo "test 2 4 5 3 1"
./push_swap 2 4 5 3 1 | wc -l

echo "test 2 4 1 3 5"
./push_swap 2 4 1 3 5 | wc -l

echo "test 2 4 1 5 3"
./push_swap 2 4 1 5 3 | wc -l

echo "test 2 4 3 5 1"
./push_swap 2 4 3 5 1 | wc -l

echo "test 2 4 3 1 5"
./push_swap 2 4 3 1 5 | wc -l

echo "test 3 1 2 4 5"
./push_swap 3 1 2 4 5 | wc -l

echo "test 3 1 2 5 4"
./push_swap 3 1 2 5 4 | wc -l

echo "test 3 1 4 5 2"
./push_swap 3 1 4 5 2 | wc -l

echo "test 3 1 4 2 5"
./push_swap 3 1 4 2 5 | wc -l

echo "test 3 1 5 2 4"
./push_swap 3 1 5 2 4 | wc -l

echo "test 3 1 5 4 2"
./push_swap 3 1 5 4 2 | wc -l

echo "test 3 2 1 4 5"
./push_swap 3 2 1 4 5 | wc -l

echo "test 3 2 1 5 4"
./push_swap 3 2 1 5 4 | wc -l

echo "test 3 2 4 5 1"
./push_swap 3 2 4 5 1 | wc -l

echo "test 3 2 4 1 5"
./push_swap 3 2 4 1 5 | wc -l

echo "test 3 2 5 1 4"
./push_swap 3 2 5 1 4 | wc -l

echo "test 3 2 5 4 1"
./push_swap 3 2 5 4 1 | wc -l

echo "test 3 4 5 2 1"
./push_swap 3 4 5 2 1 | wc -l

echo "test 3 4 5 1 2"
./push_swap 3 4 5 1 2 | wc -l

echo "test 3 4 2 1 5"
./push_swap 3 4 2 1 5 | wc -l

echo "test 3 4 2 5 1"
./push_swap 3 4 2 5 1 | wc -l

echo "test 3 4 1 5 2"
./push_swap 3 4 1 5 2 | wc -l

echo "test 3 4 1 2 5"
./push_swap 3 4 1 2 5 | wc -l

echo "test 3 5 1 2 4"
./push_swap 3 5 1 2 4 | wc -l

echo "test 3 5 1 4 2"
./push_swap 3 5 1 4 2 | wc -l

echo "test 3 5 2 4 1"
./push_swap 3 5 2 4 1 | wc -l

echo "test 3 5 2 1 4"
./push_swap 3 5 2 1 4 | wc -l

echo "test 3 5 4 1 2"
./push_swap 3 5 4 1 2 | wc -l

echo "test 3 5 4 2 1"
./push_swap 3 5 4 2 1 | wc -l

echo "test 4 1 2 3 5"
./push_swap 4 1 2 3 5 | wc -l

echo "test 4 1 2 5 3"
./push_swap 4 1 2 5 3 | wc -l

echo "test 4 1 3 5 2"
./push_swap 4 1 3 5 2 | wc -l

echo "test 4 1 3 2 5"
./push_swap 4 1 3 2 5 | wc -l

echo "test 4 1 5 2 3"
./push_swap 4 1 5 2 3 | wc -l

echo "test 4 1 5 3 2"
./push_swap 4 1 5 3 2 | wc -l

echo "test 4 2 5 3 1"
./push_swap 4 2 5 3 1 | wc -l

echo "test 4 2 5 1 3"
./push_swap 4 2 5 1 3 | wc -l

echo "test 4 2 3 1 5"
./push_swap 4 2 3 1 5 | wc -l

echo "test 4 2 3 5 1"
./push_swap 4 2 3 5 1 | wc -l

echo "test 4 2 1 5 3"
./push_swap 4 2 1 5 3 | wc -l

echo "test 4 2 1 3 5"
./push_swap 4 2 1 3 5 | wc -l

echo "test 4 3 1 2 5"
./push_swap 4 3 1 2 5 | wc -l

echo "test 4 3 1 5 2"
./push_swap 4 3 1 5 2 | wc -l

echo "test 4 3 2 5 1"
./push_swap 4 3 2 5 1 | wc -l

echo "test 4 3 2 1 5"
./push_swap 4 3 2 1 5 | wc -l

echo "test 4 3 5 1 2"
./push_swap 4 3 5 1 2 | wc -l

echo "test 4 3 5 2 1"
./push_swap 4 3 5 2 1 | wc -l

echo "test 4 5 3 2 1"
./push_swap 4 5 3 2 1 | wc -l

echo "test 4 5 3 1 2"
./push_swap 4 5 3 1 2 | wc -l

echo "test 4 5 2 1 3"
./push_swap 4 5 2 1 3 | wc -l

echo "test 4 5 2 3 1"
./push_swap 4 5 2 3 1 | wc -l

echo "test 4 5 1 3 2"
./push_swap 4 5 1 3 2 | wc -l

echo "test 4 5 1 2 3"
./push_swap 4 5 1 2 3 | wc -l

echo "test 5 1 2 3 4"
./push_swap 5 1 2 3 4 | wc -l

echo "test 5 1 2 4 3"
./push_swap 5 1 2 4 3 | wc -l

echo "test 5 1 3 4 2"
./push_swap 5 1 3 4 2 | wc -l

echo "test 5 1 3 2 4"
./push_swap 5 1 3 2 4 | wc -l

echo "test 5 1 4 2 3"
./push_swap 5 1 4 2 3 | wc -l

echo "test 5 1 4 3 2"
./push_swap 5 1 4 3 2 | wc -l

echo "test 5 2 4 3 1"
./push_swap 5 2 4 3 1 | wc -l

echo "test 5 2 4 1 3"
./push_swap 5 2 4 1 3 | wc -l

echo "test 5 2 3 1 4"
./push_swap 5 2 3 1 4 | wc -l

echo "test 5 2 3 4 1"
./push_swap 5 2 3 4 1 | wc -l

echo "test 5 2 1 4 3"
./push_swap 5 2 1 4 3 | wc -l

echo "test 5 2 1 3 4"
./push_swap 5 2 1 3 4 | wc -l

echo "test 5 3 1 2 4"
./push_swap 5 3 1 2 4 | wc -l

echo "test 5 3 1 4 2"
./push_swap 5 3 1 4 2 | wc -l

echo "test 5 3 2 4 1"
./push_swap 5 3 2 4 1 | wc -l

echo "test 5 3 2 1 4"
./push_swap 5 3 2 1 4 | wc -l

echo "test 5 3 4 1 2"
./push_swap 5 3 4 1 2 | wc -l

echo "test 5 3 4 2 1"
./push_swap 5 3 4 2 1 | wc -l

echo "test 5 4 3 2 1"
./push_swap 5 4 3 2 1 | wc -l

echo "test 5 4 3 1 2"
./push_swap 5 4 3 1 2 | wc -l

echo "test 5 4 2 1 3"
./push_swap 5 4 2 1 3 | wc -l

echo "test 5 4 2 3 1"
./push_swap 5 4 2 3 1 | wc -l

echo "test 5 4 1 3 2"
./push_swap 5 4 1 3 2 | wc -l

echo "test 5 4 1 2 3"
./push_swap 5 4 1 2 3 | wc -l

echo "\n\n---- FIN TEST 5 -----\n\n"

echo "Full Error\n"
./push_swap 5 4 1 2 3 8 8

echo "\n"
./push_swap 5 4 1 2 3 8+8

echo "\n"
./push_swap 5 4 1 2 3 8-8

echo "\n"
./push_swap 5 4 1 2 3 - 8

echo "\n"
./push_swap 5 4 1 2 3 + 8

echo "\n"
./push_swap "5 4 1 2 3 8+8"

echo "\n"
./push_swap 5 4 1 2 3 +8 8

echo "\n"
./push_swap "5 4 1 2 3 8-8"

echo "\n"
./push_swap "5 4 1 2 3 - 8"

echo "\n"
./push_swap "5 4 1 2 3 + 8"

echo "\n"
./push_swap "5 4" 1 2 "3 8+8"

echo "\n"
./push_swap "5 4" 1 2 "3 8-8"

echo "\n"
./push_swap "5 4" 1 2 "3 - 8"

echo "\n"
./push_swap "5 4" 1 2 "3 + 8"

echo "\n"
./push_swap "--5 4" 1 2 "3 + 8"

echo "\n"
./push_swap "5- 4" 1 2 "3 + 8"

echo "\n"
./push_swap 0 1 2 18446744073709551615

echo "\n"
./push_swap 99999999999999999999999999999999999999999999999999999999999999999999999 0 9

echo "\n\n---- FIN TEST ERRORS -----\n\n"

echo "Test multi args"

echo "\n"
./push_swap "5 4" 1 2 "3 8"

echo "\n"
./push_swap "5 4" 1 2 "3 -8"

echo "\n"
./push_swap "5 4" 1 2 "3 +8"

echo "\nTest valgrind\n"

echo "\n"
valgrind ./push_swap ""

echo "\n\n\n\n"

echo "\n"
valgrind ./push_swap

echo "\n\n\n\n"

echo "\n"
valgrind ./push_swap "5 4" 1 2 "3 + 8"

#ARG="435 163 351 376 394 469 353 199 268 132 24 1 228 116 226 127 333 360 4 155 441 203 473 12 120 157 396 377 63 478 281 258 171 186 429 122 232 249 402 298 485 89 336 498 200 403 53 149 76 423 387 280 147 344 94 70 409 391 41 114 354 34 64 442 308 80 40 28 345 39 124 220 347 491 468 175 290 332 488 307 235 348 317 126 180 309 320 475 388 343 411 410 446 282 364 108 366 452 205 22 141 363 500 90 284 313 245 14 319 92 88 138 384 143 50 113 10 85 293 254 77 328 386 299 292 483 369 86 144 325 125 487 2 273 436 331 323 17 294 264 19 101 497 243 460 390 474 397 326 233 371 177 173 164 9 400 359 382 13 168 451 301 251 15 26 453 161 262 137 75 271 470 338 395 447 303 300 318 404 87 74 57 204 219 83 225 59 341 455 472 221 426 142 3 495 329 217 194 51 193 158 78 456 111 117 95 239 154 131 255 346 393 358 265 253 65 427 434 304 133 408 454 38 197 260 110 170 21 407 486 23 242 188 91 362 433 128 399 419 261 295 355 62 55 315 424 102 372 192 130 231 49 106 374 330 223 286 99 181 381 439 414 210 285 480 440 465 68 112 379 66 213 190 489 270 73 20 234 47 471 229 335 420 256 479 16 310 349 93 18 187 462 484 202 209 201 179 494 215 121 46 52 151 482 361 206 365 227 247 432 208 218 134 458 466 459 36 30 207 438 467 416 174 97 212 443 196 461 314 184 176 71 267 236 216 123 148 79 312 25 81 43 156 6 367 496 305 259 405 237 29 129 84 58 165 60 389 214 499 321 322 278 211 421 191 340 252 406 248 140 327 238 48 342 166 67 378 44 380 72 272 291 115 383 31 401 306 32 337 324 375 241 257 145 444 288 159 195 98 431 109 8 135 189 82 167 481 370 96 183 178 477 283 492 352 350 119 37 425 311 428 279 297 316 7 398 172 450 339 11 136 276 198 418 27 244 222 437 42 69 33 182 287 105 162 275 107 152 224 422 240 266 412 334 457 448 392 357 356 250 185 100 493 160 146 45 445 230 476 246 35 296 373 54 430 413 263 118 490 463 385 169 103 104 415 153 368 274 61 464 150 139 269 5 417 56 449 289 277 302"; ./push_swap $ARG | ./checker_linux $ARG
#ARG="483 245 496 292 327 176 437 495 262 89 329 200 310 160 172 369 150 322 357 362 81 202 214 296 238 57 336 413 447 323 134 266 61 215 297 162 113 461 430 231 400 471 279 440 455 489 396 6 209 346 427 133 97 115 216 17 432 358 234 34 463 363 448 203 283 230 226 138 267 481 490 354 307 64 210 40 453 368 149 289 20 95 402 464 473 45 178 317 312 286 207 28 218 260 460 127 499 38 86 59 66 171 470 68 185 152 132 141 156 414 32 184 254 198 163 58 436 306 395 60 168 118 349 201 52 103 391 281 417 44 5 165 482 418 339 213 419 316 196 431 123 353 284 259 25 244 243 85 99 493 30 445 110 376 405 472 416 13 225 303 222 143 170 347 313 1 29 366 479 356 352 378 35 452 129 382 469 125 340 311 334 239 375 102 406 476 280 120 121 408 348 180 43 497 106 167 229 428 51 488 269 434 21 252 166 100 403 112 421 439 55 73 11 94 446 498 410 105 450 301 290 109 8 321 429 393 392 183 235 199 449 117 37 380 271 186 194 475 500 381 197 409 91 148 394 261 250 204 407 227 273 114 288 221 443 293 258 195 467 212 48 337 157 263 130 104 332 211 423 371 343 389 324 240 264 491 71 46 326 426 111 377 256 77 22 174 401 41 456 53 441 287 372 101 438 360 387 425 492 72 399 300 39 12 144 31 253 151 146 459 175 136 485 444 309 159 351 415 92 242 268 126 422 217 33 480 249 155 361 192 397 4 93 75 128 272 374 298 359 328 424 305 384 188 247 7 79 15 47 457 275 478 468 124 494 294 248 274 355 23 299 26 208 67 65 466 277 70 308 116 153 282 383 345 179 320 107 10 474 74 364 477 78 108 191 373 182 189 420 462 142 390 442 388 88 302 228 335 76 291 62 139 140 193 276 433 147 27 131 19 164 161 3 365 315 487 367 304 411 96 56 122 270 187 241 224 16 341 219 350 177 169 331 18 246 158 435 63 220 285 236 379 205 232 318 385 404 333 80 314 190 98 454 90 54 42 386 36 342 458 237 344 83 251 319 49 255 257 2 69 82 181 484 154 87 50 206 325 119 137 295 338 265 412 370 173 145 278 398 135 486 223 14 84 9 451 465 24 233 330"; ./push_swap $ARG | ./checker_linux $ARG
# ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
