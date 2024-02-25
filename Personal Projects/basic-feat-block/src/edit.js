/**
 * Retrieves the translation of text.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-i18n/
 */
import { __ } from '@wordpress/i18n';

/**
 * React hook that is used to mark the block wrapper element.
 * It provides all the necessary props like the class name.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-block-editor/#useblockprops
 */
import { InspectorControls, useBlockProps } from '@wordpress/block-editor';
import { PanelBody, TextControl, TextareaControl, ToggleControl } from '@wordpress/components';

/**
 * The edit function describes the structure of your block in the context of the
 * editor. This represents what the editor will render when the block is used.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/block-api/block-edit-save/#edit
 *
 * @return {Element} Element to render.
 */
export default function Edit( { attributes, setAttributes } ) {
  const { 
    featTitle,
    featPrerequisites,
    featBenefits,
    showSpecialField, featSpecials} = attributes;

	return (
    <>
      <InspectorControls>
        <PanelBody title={ __( 'Settings', 'basic-feat-block' ) }>
          <TextControl
            label={ __(
              'Feat Title',
              'basic-feat-block'
            )}
            value={ featTitle || '' }
            onChange={ ( value ) =>
              setAttributes( { featTitle: value } )
            }
          />
          <TextControl
            label={ __(
              'Feat Prerequisites',
              'basic-feat-block'
            )}
            value={ featPrerequisites || '' }
            onChange={ ( value ) =>
              setAttributes( { featPrerequisites: value } )
            }
          />
          <TextareaControl
            label={ __(
              'Feat Benefits',
              'basic-feat-block'
            )}
            value={ featBenefits || '' }
            onChange={ ( value ) =>
              setAttributes( { featBenefits: value } )
            }
          />
          <ToggleControl
            checked={ !! showSpecialField }
            label={ __(
              'Feat has \'Special\' field',
              'basic-feat-block'
            )}
            onChange={ () =>
              setAttributes( {
                showSpecialField: ! showSpecialField,
              })
            }
          />
          { showSpecialField && (
            <TextControl
              label={ __(
                'Feat Specials',
                'basic-feat-block'
              )}
              value={ featSpecials || '' }
              onChange={ ( value ) =>
                setAttributes( { featSpecials: value } )
              }
            />
          )}
        </PanelBody>
      </InspectorControls>

      <div { ...useBlockProps() }>
        <h4>{featTitle}</h4>
        <p><strong>Prerequisite(s): </strong>{featPrerequisites}</p>
        <p><strong>Benefit(s): </strong>{featBenefits}</p>
        { showSpecialField &&
          <p><strong>Special: </strong>{featSpecials}</p>
        }
      </div>
    </>
	);
}
