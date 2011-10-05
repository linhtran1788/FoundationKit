#import "NSManagedObject+FKAdditions.h"
#import "NSObject+FKDescription.h"
#import <objc/runtime.h>

@implementation NSManagedObject (FKAdditions)

- (NSString *)description {
  return [NSObject autogeneratedDescriptionOf:self];
}

- (void)setStringValue:(NSString *)stringValue forKey:(NSString *)key {
  objc_property_t property = class_getProperty([self class], [key cStringUsingEncoding:NSUTF8StringEncoding]);
  const char* propertyAttributes = property_getAttributes(property);
  
  if (strstr(propertyAttributes, "NSString") != NULL) {
    [self setValue:stringValue forKey:key];
  } else if (strstr(propertyAttributes, "NSNumber") != NULL) {
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    [formatter setNumberStyle:NSNumberFormatterDecimalStyle];
    
    [self setValue:[formatter numberFromString:stringValue] forKey:key];
  } else {
    // TODO: add more supported types
    FKAssert(NO, @"The type of the property '%@' is not supported.", key);
  }
}

- (id)userInfoValueForKey:(NSString *)key ofProperty:(NSString *)property {
  for (NSPropertyDescription *propertyDescription in self.entity.properties) {
    if ([propertyDescription.name isEqualToString:property]) {
      return [[propertyDescription userInfo] valueForKey:key];
    }
  }
  
  return nil;
}

@end
