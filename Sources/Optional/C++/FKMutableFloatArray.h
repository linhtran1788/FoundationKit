// Part of FoundationKit http://foundationk.it

#import <Foundation/Foundation.h>

#define kFKMutableFloatArrayNoValue   CGFLOAT_MIN

/**
 FKMutableFloatArray is a simple Objective C - Wrapper around a C++ STL container to store a 
 variable number of CGFloats. If you deal with a lot of CGFloats, NSArray is a lot of overhead
 because you cannot store CGFloat variables directy, you have to box and unbox them into a NSNumber.
 
 Because this class makes use of the C++ STL you have to link to the C++ Runtime library, if you use
 FKMutableFloatArray. Therefore you have to add "-lstdc++" to "other linker flags".
 */
@interface FKMutableFloatArray : NSObject

/** The number of floats stored in the array. */
@property (nonatomic, readonly) NSUInteger count;
/** check whether the array is empty */
@property (nonatomic, readonly, getter = isEmpty) BOOL empty;


/**
 Appends a number to the end of the array.
 
 @param number The number to append to the end of the array.
 */
- (void)addNumber:(CGFloat)number;

/**
 Inserts a number at a specific position in the array.
 
 @param number The number to insert in the array.
 @param index The position the number gets inserted before.
 */
- (void)insertNumber:(CGFloat)number atIndex:(NSUInteger)index;

/**
 Removes all numbers from the array. After this operation `isEmpty` returns YES.
 */
- (void)removeAllNumbers;

/**
 Removes a number at at specific position.
 
 @param index The position of the number to remove.
 */
- (void)removeNumberAtIndex:(NSUInteger)index;

/**
 Returns the number at the given index. This method is faster than numberOrNoValueAtIndex but can crash, if the index is out of bounds.
 
 @return The number stored at the index.
 @param index The index of the number to return.
 @see numberOrNoValueAtIndex
 */
- (CGFloat)numberAtIndex:(NSUInteger)index;

/**
 Returns the number at the given index. This method performs a bound-check and is therefore slower than numberAtIndex.
 
 @return The number stored at the index, or `kFKMutableFloatArrayNoValue` if the index is greater or equal the number of numbers stored.
 @param index The index of the number to return.
 @see numberAtIndex
 */
- (CGFloat)numberOrNoValueAtIndex:(NSUInteger)index;

/**
 REturns the first number in the array.
 
 @return The first number in the array, or `kFKMutableFloatArrayNoValue` if the array is empty.
 */
- (CGFloat)firstNumber;

/**
 Returns the last number in the array.
 
 @return The last number in the array, or `kFKMutableFloatArrayNoValue` if the array is empty.
 */
- (CGFloat)lastNumber;

/**
 Returns the index of a given number in the array.
 
 @return The index of the number if it was found, or `NSNotFound` otherwise.
 */
- (NSUInteger)indexOfNumber:(CGFloat)number;

@end
